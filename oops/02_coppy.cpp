#include<iostream>
#include <conio.h>
using namespace std;
class teacher
{
public:
    string name;
    string depertment;
    // not pointing to any memory.....
    double *commptr;
    teacher(string name, string depertment, double comm)
    {
        this->name = name;
        this->depertment = depertment;
        // allocate memory for commptr....
        commptr = new double;
        // commptr is pointing there we store comm....
        *commptr = comm;
    }
    // this is a custom coppy and deep coppy of teacher constructer....
    teacher(teacher &obj){
        this->name = obj.name;
        this->depertment = obj.depertment;
        // this->commptr = obj.commptr;
                                          // to make deep copy of this
        this->commptr = new double(*obj.commptr);
    }
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Depertment: " << depertment << endl;
        cout << "Comment: " << *commptr << endl;
    }
};

int main()
{
    teacher t1("sacihi", "cse", 2389);
    teacher t2(t1);
    t1.displayDetails();
    *(t2.commptr) = 343984;
    t1.displayDetails();
    return 0;
}
