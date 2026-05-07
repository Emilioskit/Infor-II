#include "students.hpp"
#include <iostream>
using namespace std;

void Student::prt() { //to do the function declaration
	cout << name << ", " << average << endl;
}

void Student::get() {
	cout << "Name, Average?";
	cin >> name >> average;
}

bool passed(Student* st) { 

	if ((*st).average >= 5.0) {
		return true;	
	}
	else {
		return false;
	}
}