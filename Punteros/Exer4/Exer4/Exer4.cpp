#include <iostream>
using namespace std;

int main() {
	int row, col;

	float** data; //pointer to pointer to flot

	cout << "Filas"; cin >> row;
	cout << "columnas"; cin >> col;

	//allocate memory for each row. We tell it how many rows I want
	data = new float*[row];

	//now allocate for the columns of each row
	for (int i = 0; i < row  ; ++i) {
		data[i] = new float[col];
	}

	//FILL IT
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;j++) {
			cin >> data[i][j];
		}
	}

	//PRINT
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;j++) {
			cout<< i << "," << j <<": " << data[i][j]<< endl;
		}
	}

	//FREE MEMORY
	for (int i = 0; i < row; i++) {
		delete[] data[i];
	}

	delete[] data;

	return 0;
}