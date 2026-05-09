#include "Employee.hpp"
#include <iostream>
using namespace std;

void Employee::show_info() {
	cout << "Employee" << endl; cout << salary;
	
}

void Manager::show_info() {
	cout << (*this).getName() << (*this).GetSalary() << degree<< endl;
}

void Worker::show_info() {
	cout << (*this).getName() << (*this).GetSalary() << position<< endl;
}

void Officer::show_info() {
	cout << (*this).getName() << (*this).GetSalary() << position << endl;
}

void Technician::show_info() {
	cout << (*this).getName() << (*this).GetSalary() << position << endl;
}