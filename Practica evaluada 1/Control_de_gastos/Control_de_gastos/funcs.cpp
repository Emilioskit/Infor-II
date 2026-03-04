#include "funcs.hpp"
#include <iostream>
using namespace std;

void cargarGasto(Gasto gastos[], int& num) {
	cout << "Nombre? "; cin >> gastos[num].nombre;
	cout << endl << "Valor? "; cin >> gastos[num].valor;
	cout << endl << "dia? "; cin >> gastos[num].dia;

	num++;
}

void verGastos(Gasto gastos[], int num) { //Gasto gastos[] ===== Gasto* gastos
	cout << "Lista de gastos: " << endl;
	double total = 0;

	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << "\t" << gastos[i].nombre << " " << gastos[i].valor << " " << gastos[i].dia << endl;
			total = total + gastos[i].valor;
		}

		cout << "Gasto total: " << total << endl;
	}

	else {
		cout << "No hay gastos" << endl;
	}
	
}