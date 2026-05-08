#include "fraction.hpp"

void Fraction::simplify() {
	long m, n, r;
	if (num < den) { m = den;n = num; }
	else { m = num;n = den; }
	while ((r = m % n) != 0) {
		m = n;
		n = r;
	}
	num /= n;
	den /= n;
}

//CONSTRUCTOR
Fraction::Fraction(long n, long d): num(n), den(d) {
	(*this).simplify();

}

//k * f
Fraction operator*(int k, const Fraction& f) {
	return Fraction(f.num * k, f.den);
}
//f*k
Fraction Fraction::operator*(int k) {
	return Fraction(num * k, den);

}

//mutiply two fractions
Fraction Fraction::operator*(const Fraction& other) {
	return Fraction(num * other.num, den * other.den);

}

// k / f
Fraction operator/(int k, const Fraction& f) {
	return Fraction(k * f.den, f.num);
}

// f / k
Fraction Fraction::operator/(int k) {
	return Fraction(num, den * k);
}

//sum
Fraction Fraction::operator+(const Fraction& other) {
	return Fraction(num + other.num, den + other.den);
}

//substract
Fraction Fraction::operator-(const Fraction& other) {
	return Fraction(num - other.num, den - other.den);

}

//STREAM SHIT

ostream& operator<<(ostream& co, Fraction& f) { //DO NOT FORGET AMPERSAN &&&
	co << f.num << "/" << f.den;
	return co;
}
istream& operator>>(istream& ci, Fraction& f) {
	cout << "Enter num / den: ";
	ci >> f.num >> f.den;

	f.simplify();

	return ci;
}