#include <iostream>
#include <conio.h>
using namespace std;
class teacher
{
private:
    // data members in class....
    double salery;

public:
    // constructor...
    string name;
    string depertment;
    string comm;
    teacher() {
        cout << "this is a teacher constructor\n";
        depertment="CSE";
    }
    // parameterized constructor
    teacher(string name, double s, string d){
        cout << "this is a teacher constructor with parameters\n";
        this->name = name;
        salery = s;
        depertment = d;
    }
    // methods in class.......
    // settrt...
    void setsalery(double sal)
    {
        salery = sal;
    }
    // getter...
    double getsalery()
    {
        cout<<"this is the name of pramt.. constructor : "<<name;
        cout<<"\nthis is the salary.. constructor : "<<salery;
        cout << "\ndepth :" << depertment;
        return salery;
    }
};

int main()
{
    // cout << "main class\n";
    // teacher t1;
    // // t1.salery = 2324; not accessable......because of it is private
    // t1.name = "sachin";
    // t1.setsalery(3233);
    // cout << t1.name << " salery is : " << t1.getsalery();
    // cout << "\nwhere dept is  : " << t1.depertment;
    teacher t2;
    teacher t1("student", 32323, "cse");
    t2.comm = "hi";
    cout <<""<< t2.comm<<"\n";
    t1.getsalery();
    return 0;
}
