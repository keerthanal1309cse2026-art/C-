
#include <iostream>
#include <string>
using namespace std;

class student
{
private:
    int rollno;
    string name;

public:
    // Constructor
    student(int r, string n) : rollno(r), name(n)
    {
        cout << "Student object created" << endl;
    }

    // Member function
    void display()
    {
        cout << "Roll Number: " << rollno << endl;
        cout << "Name: " << name << endl;
    }

    // Destructor
    ~student()
    {
        cout << "Student object destroyed" << endl;
    }
};

int main()
{
    student s1(101, "arun");
    s1.display();

    return 0;
}
