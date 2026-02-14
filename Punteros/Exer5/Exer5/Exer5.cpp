#include <iostream>
using namespace std;

int main() {
	//intilizae matrix
	double** matrix;
	int rows, cols;

	cout << "Row?"; cin >> rows;
	cout << "Col?"; cin >> cols;

	matrix = new double*[rows];

	for (int i = 0; i < rows; i++) {
		matrix[i] = new double[cols];
	}

	//add values
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols;j++) {
			cin >> matrix[i][j];
		}
	}

	//show
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols;j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	//Intiliaze vector
	double* vector;
	int len;
	cout << "length of vector?"; 
	cin >> len;
	while (len != cols) { //COLS MUST BE EQUAL TO LENGTH OF VECTOR!!
		cout << "len debe ser igual a cols. Intente de nuevo!!";
		cin >> len;
	}

	vector = new double[len];

	//fill it up
	for (int i = 0; i < len; i++) {
		cin >> vector[i];
	}

	//show
	for (int i = 0; i < len; i++) {
		cout << vector[i] << " ";
	}

	//MULTYPLY BOTH!!
	double* result_vector;
	result_vector = new double[rows];


	for (int i = 0; i < rows; i++) {
		double acum = 0;
		for (int j = 0; j < cols; j++) { //recorremos matriz
			acum = acum + matrix[i][j] * vector[j];
		}
		result_vector[i] = acum;
	}

	//show
	for (int i = 0; i < rows; i++) {
		cout << result_vector[i] << " ";
	}


	//FREE MEMORY
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i]; //borramos los punteros de dentro
	}

	delete[] matrix; //borramos el puntero externo
	delete[] vector;
	delete[] result_vector;

	return 0;


}