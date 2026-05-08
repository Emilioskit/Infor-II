#include <iostream>
using namespace std;

class Fraction {
	long num, den;

public:
	Fraction(long n = 1, long d = 1);

	//multiply by k
	friend Fraction operator*(int, const Fraction&);
	Fraction operator*(int);

	//mutiply two fractions
	Fraction operator*(const Fraction&);

	//divide by k
	friend Fraction operator/(int, const Fraction&);
	Fraction operator/(int);

	//sum
	Fraction operator+(const Fraction&);

	//substract
	Fraction operator-(const Fraction&);

	//ostream shit
	friend ostream& operator<<(ostream&, Fraction&);
	friend istream& operator>>(istream&, Fraction&);

private:
	void simplify();

	

};