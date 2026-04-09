using namespace std;
#include <iostream>
//HERE JUST CLASS DEFINTIONS (NO IMPLEMENTATION OF METHODS)

class Fraction {
	int num, den; //private variables --> num/dem

public:
	Fraction(int n = 1, int d = 1); //constructor default as 1

	~Fraction(); //destructor -> Even if you don’t define a destructor, C++ creates one and your 
								 //object is still destroyed when it goes out of scope — 
								 // you just don’t see it.

	Fraction add(Fraction& f);
	void prt() { //here we do implement it because it is short
		cout << "[" << num << "/" << den << "] ";
	}

private:
	void simplify();

};
