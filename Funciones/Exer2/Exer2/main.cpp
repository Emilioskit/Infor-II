#include "funcs.hpp"
#include <iostream>
using namespace std;

int main() {
	int A, B;
	cout << "Enter A: "; cin >> A;
	cout << "Enter B: "; cin >> B;

	Permute(A, B); //switches them if A > B

	for (int i = A; i <= B; i++) {
		if (prime(i)) {
			cout << i <<endl;
		}
	}
	return 0;
}