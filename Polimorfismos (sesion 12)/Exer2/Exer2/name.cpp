#include <iostream>
using namespace std;
#include "Employee.hpp"
#define NUM_EMPLOYEES 6
int main() {
	//Employee Rafa("Rafa");
	//Manager Mario("Mario");
	//Worker Anton("Anton");
	//Officer Luis("Luis");
	//Technician Pablo("Pablo");

	//// The type of object pointed by a pointer to the base class
	//// determines the function that is being called
	//Employee* pe;

	//cout << "\nInheritance and Polymorphism:\n" << endl;

	//pe = &Rafa;     pe->show_info();
	//pe = &Mario;    pe->show_info();
	//pe = &Anton;    pe->show_info();
	//pe = &Luis;     pe->show_info();
	//pe = &Pablo;    pe->show_info();

	//cout << "I finished..." << endl;

	//=========================================================
	
	//Employee* EmployeeList[NUM_EMPLOYEES];

	//EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
	//EmployeeList[1] = new Manager("Juan Perez", 38000, "Engineer");

	//EmployeeList[2] = new Officer("Pedro Egia", 18000, "Officer 1");
	//EmployeeList[3] = new Officer("Luisa Penia", 15000, "Officer 2");

	//EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
	//EmployeeList[5] = new Technician("Amaia Bilbao", 12000, "Electrician");

	//for (int i = 0; i < NUM_EMPLOYEES;i++) {
	//	EmployeeList[i]->show_info();
	//}


	//=============================================================
    int n;
    cout << "How many employees? ";
    cin >> n;

    Employee** EmployeeList = new Employee*[n]; //emplyee is a pointer to pointers??!

    int counter = 0;
    int op;

    while (1) {

        cout << "\nMENU\n";
        cout << "1. Add employee\n";
        cout << "2. Show employees\n";
        cout << "3. Search by name\n";
        cout << "4. Exit\n";
        cout << "Option: ";
        cin >> op;

        if (op == 1) {

            if (counter >= n) {
                cout << "Employee list is full.\n";
                continue;
            }

            int type;
            cout << "1.Manager 2.Officer 3.Technician: ";
            cin >> type;

            string name;
            long salary;
            string extra;

            cout << "Name: ";
            cin >> name;

            cout << "Salary: ";
            cin >> salary;

            if (type == 1) {
                cout << "Degree: ";
                cin >> extra;

                EmployeeList[counter] =
                    new Manager(name, salary, extra.c_str());
            }
            else if (type == 2) {
                cout << "Position: ";
                cin >> extra;

                EmployeeList[counter] =
                    new Officer(name, salary, extra.c_str());
            }
            else if (type == 3) {
                cout << "Position: ";
                cin >> extra;

                EmployeeList[counter] =
                    new Technician(name, salary, extra.c_str());
            }
            else {
                cout << "Invalid type.\n";
                continue;
            }

            counter++;
        }

        else if (op == 2) {

            int type;
            cout << "1.All 2.Manager 3.Officer 4.Technician: ";
            cin >> type;

            for (int i = 0; i < counter; i++) {

                if (type == 1) {
                    EmployeeList[i]->show_info();
                }
                else if (type == 2 && dynamic_cast<Manager*>(EmployeeList[i])) {
                    EmployeeList[i]->show_info();
                }
                else if (type == 3 && dynamic_cast<Officer*>(EmployeeList[i])) {
                    EmployeeList[i]->show_info();
                }
                else if (type == 4 && dynamic_cast<Technician*>(EmployeeList[i])) {
                    EmployeeList[i]->show_info();
                }
            }
        }

        else if (op == 3) {

            string searchName;
            cout << "Name to search: ";
            cin >> searchName;

            bool found = false;

            for (int i = 0; i < counter; i++) {
                if (EmployeeList[i]->getName() == searchName) {
                    EmployeeList[i]->show_info();
                    found = true;
                }
            }

            if (!found) {
                cout << "Employee not found.\n";
            }
        }

        else if (op == 4) {

            for (int i = 0; i < counter; i++) {
                delete EmployeeList[i];
            }

            delete[] EmployeeList;

            return 0;
        }

        else {
            cout << "Invalid option.\n";
        }
    }

}

// pe is a pointer to the base class (Employee)
// It can point to Employee, Manager, Worker, etc.
//
// Because show_info() is virtual,
// the function called depends on the REAL object
// being pointed to, not on the pointer type.