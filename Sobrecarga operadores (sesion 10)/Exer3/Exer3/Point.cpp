
#include "Point.hpp"
#include <cmath>
using namespace std;

Point::Point(double a, double b) : x(a), y(b) {}

double Point::operator-(Point& p1) {
	return sqrt((x - p1.x) * (x - p1.x) + (y - p1.y) * (y - p1.y)); //euclidean distance
}


//OVERLOADING SAME NAME OPERATOR SO IT WORKS BOTH WAYS!!
Point Point::operator*(double k) { //POINT * K 
	return Point(k * x, k * y);
}
Point operator*(double k, Point& p1) { //K * POINT
	return Point(k * p1.x, k * p1.y);
}

//COUT AND CIN
ostream& operator<<(ostream& co, Point& p1) {
	co << "x: " << p1.x << " y:" << p1.y << endl;
	return co;
}

istream& operator>>(istream& ci, Point& p1) {
	cout << "Enter x, y: ";
	ci >> p1.x >> p1.y;

	return ci;
}



