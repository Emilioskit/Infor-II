#include "Fraction.hpp"

//no need to write class Faction{... again.

//we do Fraction::(function_name)
//it is NOT a namespace. If there existed a namespace we would have to do 
//namespace::Fraciton::(function_name)

Fraction::Fraction(int n, int d) { //no put equals 1????
	num = n; den = d;
	simplify(); //acts on "this" if I put nothing before it
	// (*this).simplify() == this->simplify();

	cout << "Constructor Fraction.." << endl;
}

Fraction::~Fraction() {
	cout << "Destructor Fraction.." << endl;
	
}


Fraction Fraction::add(Fraction& f) { //need to put the return type
	long dd = den * f.den;
	long nn = num * (dd / den) + f.num *(dd / f.den);

	Fraction fs(nn, dd);
	fs.simplify();
	
	return fs;
}


void Fraction::simplify() {
	long m, n, r;
	if (num < den) {m = den; n = num;}
	else {m = num; n = den;}
	r = m % n; //remainder and n is the greates common divisor

	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	num /= n;
	den /= n;
}