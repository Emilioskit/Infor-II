#include <iostream>
using namespace std;

struct student
{
	char *name;  //NOW ITS A POINTER to a char
	double mark;
};

int main() {

	int num = 0;
	cout << "Give me Num?:";
	cin >> num;

	student* list; 
	list = new student[num];

	for (int i = 0; i < num;i++) {
		char buffer[100];
		cout << "Give Name and Mark?";
		cin >> buffer >> list[i].mark;

		list[i].name = new char[strlen(buffer) + 1]; //!!!!!!!!!!!!!!!!!! IMPORTANT PART!!
		strcpy(list[i].name, buffer);


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

	// IMPORTANT: Free each name first
	for (int i = 0; i < num; i++)
	{
		delete[] list[i].name; ///WHY FREE THIS FIRST???
	}

	delete[] list;

	return 0;
}