#include <iostream>
using namespace std;
#include "Point.hpp"

int main() {

    double k = 0.0;
    Point p1, p2;   //create objects

    cout << "Enter P1:";  cin >> p1;
    cout << "Enter P2:";  cin >> p2;

    double dist = p1 - p2;
    cout << "Distance=" << dist << endl;
    cout << "P1:" << p1 << endl;
    cout << "Enter value of K:";  cin >> k;

    Point p3 = k * p1;   //declare "*" operator as friend
    cout << "P3= " << p3 << endl;

    cout << "fin" << endl;
	
	return 0;
}