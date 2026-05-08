#include <iostream>
using namespace std;

class Point {
	double x, y;

public:
	Point(double x = 0, double y= 0);
	double operator-(Point&); //*this - (Point& a)

	Point operator*(double);
	friend Point operator*(double, Point&);

	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator>>(istream&, Point&);

};