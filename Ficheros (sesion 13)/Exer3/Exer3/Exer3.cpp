#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	string filename;
	cout << "filename??";
	cin >> filename;

	ifstream fin(filename);

	if (!fin) { //negation of fin??
		cout << "ERROR";
		return 0;
	}

	vector<double> list;
	double x = 0;
	while (true) {
		fin >> x;
		list.push_back(x);

		if (fin.eof()) break; //si llego al final?

	}

	fin.close();

	//now print all the numbers

	double sum = 0;
	double max = list[0];
	cout << "The numbers are: ";
	for (auto it = list.begin(); it != list.end(); it++) {
		sum = sum + (*it);

		if (max < (*it)) {
			max = (*it);
		}

		cout << (*it) << endl;
	}

	cout << "Average is: " << sum / list.size() << endl;
	cout << "The Max value is: " << max;



	return 0;
}