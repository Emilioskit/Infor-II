
#include <iostream>
#include <vector>
#include "vehicle.hpp"
using namespace std;

int main() {

	int op;
	vector<vehicle> list; //no need to size it?

	while (1) {
		cout << "Menu" << endl;;
		cout << "1. Add car" << endl;
		cout << "2. Print car" << endl;
		cout << "3. Erase car" << endl;
		cout << "4. Find cars" << endl;
		cout << "Which option: ";
		cin >> op;

		if (op == 1) { // Add car

			string brand;
			int hp;
			date reg;
			cout << "Enter brand? "; cin >> brand;
			reg.get();
			cout << "Enteder hp?"; cin >> hp;

			
			list.push_back(vehicle(brand, reg, hp));
		} else if (op == 2) { //print all the cars

			for (auto it = list.begin(); it != list.end(); it++){
				(*it).prt();
				cout << "\n \n";
			}

		} else if (op == 3) { //erase one
			int pos;
			cout << "Which to erase?: "; cin >> pos;
			list.erase(list.begin() + pos); // HOW DOES IT WORK???

		}
		else if (op == 4) { //print cars between two days

			//function to pass everything to days? compare if in range then print that list??
			date lower_bound;
			date higher_bound;
			cout << "Enter dates?";
			lower_bound.get();
			higher_bound.get();

			//loop through all and see if its between and print it

			for (auto it = list.begin(); it != list.end();it++) {
				date d = (*it).getReg();

				if (greaterthan(d, lower_bound) && greaterthan(higher_bound, d)) {
					(*it).prt();
				}
			}
		} else {
			return 0;
		}
	}
}