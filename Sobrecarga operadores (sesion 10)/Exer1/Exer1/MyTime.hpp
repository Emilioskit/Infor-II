#include <iostream>
using namespace std;

class MyTime {
    int hr, min;

public:
    MyTime(int h = 0, int m = 0);
    void prt();
    int operator-(MyTime& t1);
    int operator+(MyTime& other);

    friend ostream& operator<<(ostream&, MyTime&); //cout
    friend istream& operator>>(istream&, MyTime&); //cin
};

// Use friend when a function needs access to private members
// BUT should not be a member function of the class.
//
// Common case:
// operator<< and operator>> because the left operand is
// ostream/istream (cout, cin), not your class.