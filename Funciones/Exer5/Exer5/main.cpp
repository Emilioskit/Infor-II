#include <iostream>
#include "funcs.hpp"

using namespace std;

int main() {
	double x, y;
	mydata dat{ {1,2,3,4,5},{1,4,9,16,25},5 };
	prt(dat);
	cout << "Give x value:"; cin >> x;
	y = interp(dat, x);

	cout << y;
	return 0;
}