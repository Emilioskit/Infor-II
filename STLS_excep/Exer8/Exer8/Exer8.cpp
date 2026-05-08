#include <iostream>
using namespace std;

double root(double n) {
	if (n < 0) {
		throw exception();
	}
	return sqrt(n);
}

int main() {
	double a;
	cin >> a;
	try {
		cout << root(a);
	}
	catch(...){ //... handles any exception inside try
		cerr << "negative number" << endl; //cerr is cout for errors
	}
	

	

	return 0;
}