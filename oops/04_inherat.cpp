#include <iostream>
using namespace std;

// Base class (Person)
class Person {
public:
    string name;
    int age;

    // Constructor for Person
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor Called" << endl;
    }

    // void displayPerson() {
    //     cout << "Name: " << name << endl;
    //     cout << "Age: " << age << endl;
    // }
};

// Derived class (Teacher -> inherits from Person)
class Teacher : public Person {
public:
    string department;

    // Constructor for Teacher
    Teacher(string n, int a, string d) : Person(n, a) {
        this->department = d;
        cout << "Teacher Constructor Called" << endl;
    }

    // void displayTeacher() {
    //     displayPerson();
    //     cout << "Department: " << department << endl;
    // }
};

// Derived class (Professor -> inherits from Teacher)
class Professor : public Teacher {
public:
    string subject;

    // Constructor for Professor
    Professor(string n, int a, string d, string s) : Teacher(n, a, d) {
        subject = s;
        cout << "Professor Constructor Called" << endl;
    }

    void displayProfessor() {
        // displayTeacher();
        cout<< "Department: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    // Creating an object of the most derived class
    Professor p1("Dr. John", 45, "Computer Science", "Artificial Intelligence");

    // Display details of the professor
    p1.displayProfessor();

    return 0;
}
