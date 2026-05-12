#include <iostream>
using namespace std;
#include "funcs.hpp"


int main() {
	int op = 0;
	while (1) {
		cout << "Menu" << endl;
		cout << "1. Dec -> Hex" << endl;
		cout << "2. Hex -> Dex" << endl;
		cout << "3. Salir" << endl;

		cout << "Choose?"; cin >> op;

		if (op == 1) { //dec_hex

			int num;
			cout << "Enter decimal number: "; 	cin >> num;
		

			cout << dec_to_hex(num);


		}
		else if (op == 2) { //hex_dec
			string hex;
			cout << "Enter hexadecimal: "; 	cin >> hex;
		
			cout << hex_to_dec(hex);


		}
		else {
			return 0;
		}

	}

}