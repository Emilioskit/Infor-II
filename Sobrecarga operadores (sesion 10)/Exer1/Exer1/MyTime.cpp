#include "MyTime.hpp"
#include <iostream>
using namespace std;


MyTime::MyTime(int h, int m) : hr(h), min(m) {}

void MyTime::prt() {
	cout << hr << ":" << min << endl;
}

int MyTime::operator-(MyTime& t1) {
	int tm1, tm;
	tm = hr * 60 + min;
	tm1 = t1.hr * 60 + t1.min; //since it's a member function I can acces private stuff

	return abs(tm1 - tm);
}

int MyTime::operator+(MyTime& t1) {
	int tm1, tm;
	tm = hr * 60 + min;
	tm1 = t1.hr * 60 + t1.min; //since it's a member function I can acces private stuff

	return abs(tm1 + tm);
	
}

ostream& operator<<(ostream& co, MyTime& t) {
	co << t.hr << ":" << t.min << endl;
	return co;
}

istream& operator>>(istream& ci, MyTime& t) {
	cout << "Enter H:M?";
	cin >> t.hr >> t.min;
	return ci;
}