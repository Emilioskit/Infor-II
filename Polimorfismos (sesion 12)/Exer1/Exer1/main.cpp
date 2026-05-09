#include <iostream>
using namespace std;

class Employee {
protected:
	double sal;
public:
	Employee(double s) { sal = s;  }
	virtual double Payment() { return sal; }
	void prt() {
		cout << "Salary= " << Payment() << endl;
	}
};

class Manager : public Employee {
	double inc;
public:
	Manager(double s, double i) : Employee(s) { inc = i; }
	double Payment() { return sal * inc; }
};

int main() {
	Employee e1(1500);
	Manager m1(1500, 1.5);

	e1.prt();
	m1.prt();

	//without virtual it uses the base payment but with virtual it uses the paymet func from manager

	return 0;
}