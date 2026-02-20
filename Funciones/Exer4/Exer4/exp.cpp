
#include <cmath>
#include "exp.hpp"

double Exp(double x, double num) { //stops at num iterations
	double answer = 0;
	for (double i = 0; i < num; i++) {
		answer = (pow(x, i) / factorial(i)) + answer;
	}
	return answer;
}


double Exp(double x, double Error, int& num) {

	num = 1;
	double previous = 1;
	double a = 1;
	do {
		if (num != 1) {
			previous = a;
		}
		
		a = (pow(x, num) / factorial(num)) + previous;
		num++; //technically gives me terms in the formula but I do n-1 iterations
	} 
	while (abs(previous - a) > Error);
	return a;
}

double factorial(double a) { //IN .HPP IT GOES FIRST SO NO NEED TO PLACE IT FIRST HERE!!
	if (a == 0) {
		return 1;
	}
	return (a* factorial(a - 1));
}