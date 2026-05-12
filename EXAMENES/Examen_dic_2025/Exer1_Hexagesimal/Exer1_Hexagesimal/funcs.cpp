#include <iostream>
#include "funcs.hpp"
#include <string>
#include <cmath>

using namespace std;

string dec_to_hex(int n) {
	string hex = "";
	int res;
	do {


		res = (n % 16);

		if (res >= 10) { //need to change it to letters

			string letters = "ABCDEF";
			hex = letters[res - 10] + hex;

		}
		else { // just convert it to string
			hex = to_string(res) + hex;
		}
		n = n / 16;

	} while (n > 0);

	return hex;
}


int hex_to_dec(string hex) {

	int n = 0;
	int it = size(hex) - 1;
	for (int i = 0; i < size(hex); i++) {
		int b;

		if (hex[it] >= '0' && hex[it] <= '9') { //chane from str numbers to int numbers
			
			b = hex[it] - '0'; //this transforms them to numbers

		}
		else { //transform letters to numbers

			b = (hex[it] - 'A') + 10; //converts back to numbers
		}

		n = n + pow(16, i) * b; 

		it--;
		
	}
	return n;
}

// ASCII trick:
//
// Characters are stored as consecutive numbers in ASCII:
//
// '0' = 48, '1' = 49, ..., '9' = 57
// 'A' = 65, 'B' = 66, ..., 'F' = 70
//
// So:
//
// char -> int:
// '7' - '0' = 7
// 'C' - 'A' + 10 = 12
// 
// int -> char:
//
// char(7 + '0') = '7'
// char(12 - 10 + 'A') = 'C'
//
// The arithmetic produces an int ASCII code,
// then it is converted to a char.


/////
char* DecToHex(int numDec) {

	int temp = numDec;
	int digits = 0;

	//count how many in digits in hexadecimal it will take
	do {
		digits++;
		temp /= 16;
	} while (temp > 0);

	//crete de hex pointer to an array of char of digits including the end
	char* hex = new char[digits + 1];

	hex[digits] = '\0'; //must I add this !!!! yes so it does do cout

	for (int i = digits - 1; i >= 0; i--) {

		int res = numDec % 16;

		if (res < 10)
			hex[i] = char(res + '0');
		else
			hex[i] = char(res - 10 + 'A');

		numDec /= 16;
	}

	return hex;
}

int HexToDec(char* numHex) {
	
	int n = 0;
	int it = strlen(numHex) -1;
	for (int i = 0; i < strlen(numHex); i++) {
		int b;
		if (numHex[it] >= '0' && numHex[it] <= '9') { //si es numeros
			b = numHex[it] - '0';
		}
		else { //si son letras
			b = (numHex[it] - 'A') + 10;
		}
		n = n + pow(16, i) * b;
		it--;
	}

	return n;
}