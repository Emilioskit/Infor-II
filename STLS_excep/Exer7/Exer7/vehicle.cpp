# include "vehicle.hpp"
#include <iostream>

void date::prt() {
	cout << "Day: " << d << " month: " << m << " year: " << y;
}

void date::get() {
    cout << "Enter day month year: ";
    cin >> d >> m >> y;
}


//try friend function better

bool greaterthan(const date& d1,const date& d2)
{
    // compare years first
    if (d1.y > d2.y) return true;
    if (d1.y < d2.y) return false;

    // if years equal, compare months
    if (d1.m > d2.m) return true;
    if (d1.m < d2.m) return false;

    // if months equal, compare days
    return d1.d > d2.d;
}

void vehicle::prt() {
	cout <<"Brand: "<<  brand << endl;
	reg.prt();
	cout <<"\n Hp: " << hp << endl;
}

date vehicle::getReg() {
    return reg;
}