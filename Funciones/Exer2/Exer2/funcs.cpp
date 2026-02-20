#include "funcs.hpp"
#include <cmath>

// & has two meanings in C++:
// 1. &A → address-of operator (used with pointers)
// 2. int& A → reference declaration (alias to a variable)
// References are not pointers, but behave like the original variable.

void Permute(int& A, int& B) { //double& B = C; B IS C (different name only) same memory and changes affect both
	if (A > B) {
		int temp = A;
		A = B;
		B = temp;
	}
}

bool prime(int A) {
    if (A < 2) return false;   // 0,1,negatives are not prime
    if (A == 2) return true;   // 2 is prime

    for (int i = 2; i * i <= A; i++) { //CHECK UNTIL SQUARE ROOT IS MORE EFFICIENT!!
        if (A % i == 0) {
            return false;      // return ends function!!!
        }
    }
    return true;
}