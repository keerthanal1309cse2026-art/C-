
#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }

    ~Resource()
    {
        cout << "Resource released" << endl;
    }

    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    // Constructor
    explicit MySmartPointer(Resource* p) : ptr(p)
    {
    }

    // Destructor
    ~MySmartPointer()
    {
        delete ptr;
        cout << "Manual smart pointer destroyed" << endl;
    }

    // Overload arrow operator
    Resource* operator->()
    {
        return ptr;
    }

    // Prevent copying to avoid double deletion
    MySmartPointer(const MySmartPointer&) = delete;

    MySmartPointer& operator=(const MySmartPointer&) = delete;
};

int main()
{
    cout << "----- Manual RAII Smart Pointer -----" << endl;

    {
        MySmartPointer smartPtr(new Resource());
        smartPtr->use();
    }

    cout << "\n----- unique_ptr -----" << endl;

    {
        unique_ptr<Resource> uniquePtr(new Resource());
        uniquePtr->use();
    }

    cout << "\n----- shared_ptr -----" << endl;

    {
        shared_ptr<Resource> sharedPtr1(new Resource());
        shared_ptr<Resource> sharedPtr2 = sharedPtr1;

        sharedPtr1->use();

        cout << "Shared Pointer Count: "
             << sharedPtr1.use_count() << endl;
    }

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
