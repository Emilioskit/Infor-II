// Exer1.cpp 

#include <iostream>
#include "Fraction.hpp"
using namespace std;

int main() {
	int n, d;
	//Fraction f1; default 1/1

	Fraction f1(1, 4);
	cout << "Enter N, D:?", cin >> n >> d;
	Fraction f2(n, d);

	cout << "\nF1: "; f1.prt();
	cout << "\nF2: "; f2.prt();

	Fraction fs = f1.add(f2);
	cout << "\nF1 + F2 =  "; fs.prt();



	return 0;
}