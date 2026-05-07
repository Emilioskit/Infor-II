using namespace std;
#include <iostream>

int main() {
	string vec[10];

	cout << "give 10 words: ";
	for (int i = 0; i < 10; i++) {
		cin >> vec[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i; j <10; j++) {
			if (vec[i] > vec[j]) { //si es mayor, cambiamos
				//switch 
				string temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << vec[i] << endl;
	}

	return 0;
}