#include <string>
#include <iostream>
using namespace std;

// STRING VERSION (cleaner modern approach)
/*
class Employee {
protected:
    string name;

public:
    Employee(string n = "none")
        : name(n)
    {
    }
};
*/


class Employee {

//we could have used protected!!
private:
    // Private: derived classes cannot access directly
    char name[40];
    double salary;

public:

    // Base constructor
    // Copies n into the name array
    Employee(const char* n = "none", double s =0): salary(s) {

        strcpy_s(name, n);
        cout << "making employee" << endl;
    }

    // Base destructor
    ~Employee() {

        cout << "destroying employee" << endl;
    }

    // Default position
    void print_position() {

        cout << "Position not defined" << endl;
    }

    void prt() {
        cout << "Name:" << name << " salary: " << salary;
        //print name using loop for char????
    }

    // Returns pointer to first character of name
    char* GetName() {

        return name;
    }
};



class Manager : public Employee {
    // Public inheritance:
    // public Employee members stay public
    // protected stay protected

public:

    // Calls Employee constructor first
    // to initialize the inherited Employee part
    Manager(const char* n = "none", double s = 0)
        : Employee(n,s)
    {
        cout << "making manager" << endl;
    }

    ~Manager() {

        cout << "destroying manager" << endl;
    }

    // Overrides Employee version
    void print_position() {

        cout << "is a manager" << endl;
    }
};



class Worker : public Employee {

public:

    // Construct inherited Employee part first
    Worker(const char* n = "none", double s= 0)
        : Employee(n, s)
    {
        cout << "making worker" << endl;
    }

    ~Worker() {

        cout << "destroying worker" << endl;
    }

    void print_position() {

        cout << "is a worker" << endl;
    }
};



class Officer : public Worker {

public:

    // Officer inherits from Worker
    // Worker already inherits Employee
    Officer(const char* n = "none", double s = 0)
        : Worker(n, s)
    {
        cout << "making officer" << endl;
    }

    ~Officer() {

        cout << "destroying officer" << endl;
    }

    void print_position() {

        cout << "is an officer" << endl;
    }
};



class Technician : public Worker {

public:

    // Build Worker part first
    // which then builds Employee part
    Technician(const char* n = "none", double s = 0)
        : Worker(n,s ) //call parents, not grandparents
    {
        cout << "making technician" << endl;
    }

    ~Technician() {

        cout << "destroying technician" << endl;
    }

    void print_position() {

        cout << "is a technician" << endl;
    }
};