
#include <iostream>
int* generaData(int& num) { //le entra el numero de elementos -> crea vector dinamico de x length y asigna random
	
	int* vec;
	vec = new int[num]; //allocate an array of ints of "num" length to heap

	srand(time(0));  // only once

	for (int i = 0; i < num; i++) {
		vec[i] = rand() % 11;
	}

	return vec;
}


int* comprimeData(int* vec, int num, int& nnum) {

	//obtener nnum bien da igual si sea par o impar
	nnum = (num / 2) + (num%2);
	//asignamos memoria al nuevo vector
	int* new_vec;
	new_vec = new int[nnum];

	int index = 0;
	for (int i = 0; i < num - 1;i = i + 2) {
		new_vec[index] = (vec[i] + vec[i + 1]) / 2;
		index++;
	}

	if (num % 2 == 1) {
		new_vec[index] = vec[num - 1]; //le pegamos el ultimo si es que es impar
	}
	return new_vec;

}

void printData(int* vec, int num) {
	for (int i = 0; i < num; i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}