
#include <iostream>
using namespace std;
#include "students.hpp"

#define NUMS 5; //same as const??
int main() {
	//EXER1=========================================================
	/*Student s1;
	Student s2((char*)"Ana", 6.5);
	Student s3;
	s3.get();

	s1.prt();
	s2.prt();
	s3.prt();*/

	//EXER2===============================================================================
	int n = 0;
	cout << "Dyamic objects" << endl;

	Student* pl[100]; //array of pointers of type student. NO NEED TO DELETE[]. FIXED SIZE
	pl[n] = new Student((char*)"Ana", 6.0);
	(*pl[n]).prt(); //pl[n]->prt();

	int op;

	while (1) {
		cout << "** Menu **\n1.Add 2.Prt 3.Passed? 4.Exit? ";
		cin >> op;
		
		if (op == 1) {
			n++;
			pl[n] = new Student();
			(*pl[n]).get();
		}
		else if (op == 2) {
			cout << "Which number of student to print?";
			int a;
			cin >> a;
			(*pl[a]).prt();
		}
	 else if (op == 3) {
			cout << "Which number of student to see if they passed?";
			int a;
			cin >> a;
			cout << passed(pl[a]); //I pass the pointer itself
		}
		else {
			for (int i = 0; i < n; i++) {
				delete pl[i];
			}
			break;
		}
	}

	//EXER3=======================================================================

//	int num;
//	cout << "Static" << endl;
//	//int a = 2;
//	//Student vec[a]; !!!!! NOT POSSIBLE!!
//
//	int const a = 5;
//	Student vec[a]; //same as using NUMS!!
//
//	for (int i = 0;i < a;i++) { 
//		vec[i].get(); 
//	} 
//	
//	cout << "Data:" << endl; 
//	for (int i = 0;i < a;i++) { 
//		vec[i].prt(); 
//	
//	}
//
//
//	cout << "Dynamic" << endl; 
//	cout << "Enter number of students:"; 
//	cin >> num; 
//	Student* pv = new Student[num]; //now I do create a dynamic array of student objects
//
//	for (int i = 0;i < num;i++) pv[i].get();
//
//	cout << "Data:" << endl; 
//	for (int i = 0;i < num;i++) pv[i].prt();
//	
//	delete[] pv;
//
	return 0;
}