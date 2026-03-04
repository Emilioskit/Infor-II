
#include <iostream>
using namespace std;
#include "funcs.hpp"

int main() {

	//crear mi vector de gastos
	int n = 0;
	Gasto gastos[100]; //con este tamano max
	while (true) {
		

		cout << "Menu" << endl;
		cout << "1. Cargar gastos" << endl;
		cout << "2. Ver gastos" << endl;
		cout << "3. Salir" << endl;
		cout << "opcion? ";

		int opcion;
		cin >> opcion;



		switch (opcion) {
		case 1:

			cargarGasto(gastos, n);
			break;

		case 2:

			verGastos(gastos, n);
			break;

		case 3:
			return 0;
		}
	}

	return 0;
}