#include <iostream>
using namespace std;

//struct has public access by default and class is private by default
struct student
{
	char name[50]; //has a static array WOULD HAVE BEEN BETTER TO USE STRING
	//COULD PASS 50 and ERROR HAPPENS!!
	double mark; 
};

int main() {

	int num = 0;
	cout << "Give me Num?:";
	cin >> num;

	student* list; //declare pointer (list) to struct
	list = new student[num]; //assign pointer to adress of begining of class

	for (int i = 0; i < num;i++) {
		cout << "Give Name and Mark?";
		cin >> list[i].name >> list[i].mark;
	}

	double min = list[0].mark; //get first mark of first student
	int worstIndex = 0;

	//list all
	cout << "-------------------------------------" << endl;
	for (int i = 0;i < num;i++) {
		cout << list[i].name << "," << list[i].mark << endl; //automatically reads and adds them
		if (list[i].mark < min) {
			min = list[i].mark;
			worstIndex = i;
		}
	}
	cout << "-------------------------------------" << endl;
	cout << "worst case: " << list[worstIndex].name << list[worstIndex].mark << endl;
	
	delete[] list;
	return 0;
}