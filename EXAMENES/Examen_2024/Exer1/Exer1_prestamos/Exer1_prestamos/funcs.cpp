#include <iostream>
using namespace std;
#include "funcs.hpp"

int menu() {
	int op;
	cout << "Gestion de Prestamos" << endl << "1. Abrir cuenta" << endl
		<< "2. Abrir prestamos" << endl << "3. Pago de intereses" << endl
		<< "4. Reporte" << endl << "5. Salir" << endl << "\t opcion:? ";
	cin >> op;

	return op;
}

