#include <iostream>
#include <iomanip>
using namespace std;
#include "funcs.hpp"

sala::sala(char a[20][30], int fils, int cols, const char* peli, double precio, hora ho) :
	fils(fils), cols(cols), precio(precio), h(ho) {
	//copiar asientos
	for (int i = 0; i < 20;i++) {
		for (int j = 0; j < 30; j++) {
			asiento[i][j] = a[i][j];
		}
	}
	//copiar nombre
	strcpy_s(pelicula, 40, peli);
}

int menu() {
	int op;
	cout << "Menu CINES" << endl << "1. Comprar Entradas" << endl << "2. Devolver Entradas" << endl
		<< "3. Ver salas y dinero recaudado" << endl << "4. Salir" << endl << "Opc> :";
	cin >> op;

	return op;

}

char* sala::get_pelicula() {
	return pelicula;
}

void hora::prt() {
	cout << hh << ":" << min;
}

void sala::comprar() { //mostrar nombre y hora y luego toda la sala
	cout << "Pelicula: " << pelicula << endl;
	cout << "Hora: "; h.prt(); cout << endl;



	// Print top column numbers
	cout << "   "; // space for left row numbers
	for (int j = 0; j < cols; j++) {
		cout << setw(3) << j;
	}

	cout << endl;

	// Print rows
	for (int i = 0; i < fils; i++) {
		cout << setw(3) << i; // left row number

		for (int j = 0; j < cols; j++) {
			cout << setw(3) << asiento[i][j];
		}

		cout << endl;
	}

	//AHORA A COMPRAR
	int num_comprar = 0;
	cout << "Cuantas desea comprar: ? ";
	cin >> num_comprar;

	for (int i = 0; i < num_comprar; i++) {
		int fila, as;
		cout << "Fila, asiento?: "; cin >> fila; cin >> as;
		asiento[fila][as] = '1';
	}

	cout << "Precio a pagar: " << num_comprar * precio;

}

void sala :: devolver() {
	int f_dev, c_dev;
	cout << "Fila y asiento? "; cin >> f_dev >> c_dev;

	asiento[f_dev][c_dev] = '0';
	cout << "Devuleto: " << precio << " euros" << endl;
}

double sala::prt(int cont) {

	double recaudacion = 0;
	cout << "Sala " << cont << endl;
	cout << "Pelicula " << pelicula << endl;
	cout << "Hora "; h.prt();

	cout << "   ";
	for (int i = 0; i < cols; i++){
		cout << i << setw(3);
	}

	cout << endl;

	// Print rows
	for (int i = 0; i < fils; i++) {
		cout << setw(3) << i; // left row number

		for (int j = 0; j < cols; j++) {
			cout << setw(3) << asiento[i][j];

			if (asiento[i][j] == '1') {
				recaudacion = recaudacion + precio;

			}
		}

		cout << endl;
	}

	cout << "Dinero recaudado: " << recaudacion << endl;
	return recaudacion;



}