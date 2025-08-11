#include <iostream>
#include <conio.h>
using namespace std;
class student
{
public:
    string name;
    int age;
    double *cgpaptr;
    student(string n, int age,double cgpa){
        name = n;
        this->age = age;
        this->cgpaptr = new double(cgpa);
    }
    ~student(){
        delete cgpaptr;
        cout << "destroy student called";
    }
    void getter(){
        cout << "Student object created with\n name: " << name << "\n age: " << age << "\n CGPA: " << *cgpaptr << endl;

    }
};

int
main()
{
    student s1("John Doe", 18, 3.5);
    s1.getter();
    return 0;
}