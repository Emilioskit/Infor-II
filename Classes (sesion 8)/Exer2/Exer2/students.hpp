#include <cstring>
using namespace std;

class Student {
	//private by default
	char name[20];
	double average;

public://construct but I dont get it 
	Student(char* n = (char*)"joe", double a = 0) {
		strcpy_s(name, n);
		average = a;
	}
	//definitions of other functions
	void prt();
	void get();

	friend bool passed(Student*); //parameter name is optional. Its a pointer to a student object

	//destructor
	~Student(void) {} //no memory to free. Only if I had used new in here.
};