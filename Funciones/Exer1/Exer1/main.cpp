// C++ compilation notes:
//
// - The compiler reads code top → bottom.
// - A function must be DECLARED before it is used.
// - Definition can be before main() OR after if a prototype is given.
// - #include literally copies the header content where written.
// - Headers (.h) usually contain declarations.
// - .cpp files contain the actual function definitions.
// - Compilation checks declarations; linking connects definitions.

#include "FirstFunc.hpp"
#include <iostream>
using namespace std;

int main(void) {
	double x1, y1, x2, y2;
	cout << "First position?";
	cin >> x1 >> y1;

	cout << "Second position?";
	cin >> x2 >> y2;

	cout << distance(x1, y1, x2, y2);


}