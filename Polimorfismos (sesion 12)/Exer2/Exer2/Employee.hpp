#include <string>
#include <iostream>
using namespace std;

class Employee {
	string name;
	long salary;

public:
	Employee(string n = "none", long s = 0) : name(n), salary(s) {}

	virtual void show_info();
	string getName() { return name; }


	long GetSalary() { return salary; }
};

class Manager :public Employee {
protected:
	char* degree;
public:
	Manager(string n = "none",long s = 0, const char* d = (char*)"none") :Employee(n,s) {
		degree = new char[strlen(d) + 1];
		strcpy_s(degree, strlen(d) + 1, d);
	}

	~Manager() {
		delete[] degree;
	}
	void show_info();
};


class Worker :public Employee {
protected:
	char* position;
public:
	Worker(string n = "none", long s = 0, const char* p = (char*)"none") :Employee(n,s) {
		position = new char[strlen(p) + 1];
		strcpy_s(position, strlen(p) + 1, p); //destination, size, from
	}

	~Worker() {
		delete[] position;
	}

	void show_info();
};

class Officer :public Worker {
public:
	Officer(string n = "none", long s = 0, const char* p = (char*)"none") : Worker(n, s, p) {}

	void show_info();
};

class Technician :public Worker {
public:
	Technician(string n = "none", long s = 0, const char*p = (char*)"none") :Worker(n,s,p) {}

	void show_info();
};

