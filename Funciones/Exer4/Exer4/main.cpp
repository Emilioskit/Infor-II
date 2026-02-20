#include "exp.hpp"
#include <iostream>
using namespace std;

int main() {
	int o;
	cout << "Enter 1 if you want to stop at n iterarions \n Enter 2 if you want to stop at some Error";
	cin >> o;
    switch (o) {
    case 1: {
        int num;
        cout << "Enter max number of iterations: ";
        cin >> num;

        double x;
        cout << "Enter x that goes in e^x: ";
        cin >> x;

        cout << "e^x is: " << Exp(x, num);
        break;
    }

    case 2: {
        double e;
        cout << "Enter Error: ";
        cin >> e;

        double x;
        cout << "Enter x that goes in e^x: ";
        cin >> x;

        int num_iter = 0;
        cout << "e^x is: " << Exp(x, e, num_iter)
            << " and it took " << num_iter << " iterations.";
        break;
    }
    }

}