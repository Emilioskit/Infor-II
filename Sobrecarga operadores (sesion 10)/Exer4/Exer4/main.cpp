#include <iostream>
using namespace std;
#include "fraction.hpp"

int main() {
    Fraction f1(1, 4); Fraction f2(1, 2);
    Fraction f3;

    cin >> f3; //asks data for f3

    Fraction fr = f1 + f2;
    cout << f1 << " + " << f2 << " = " << fr << endl;

    Fraction fm = f1 * f2;
    cout << f1 << " * " << f2 << " = " << fm << endl;

    int k = 4;

    fr = k * f1; //Pre-multip
    cout << k << " * " << f1 << " = " << fr << endl;

    fr = k / f3; //Pre-division
    cout << k << " / " << f3 << " = " << fr << endl;

    k = 2;

    fr = f2 * k; //Post-multip
    cout << f2 << " * " << k << " = " << fr << endl;

    fr = f3 / k; //Post-division
    cout << f3 << " / " << k << " = " << fr << endl;
    return 0;
}