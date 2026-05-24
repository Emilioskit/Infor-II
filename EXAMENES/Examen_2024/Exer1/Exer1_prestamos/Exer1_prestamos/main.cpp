#include <iostream>
#include "funcs.hpp"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

#define INTERESDIARO 0.1

int main() {
	int np = 0; //cont prestamos
	vector <prestamo> lstPrestamos;
	
	int nc = 0;
	vector <cuenta> lstCuenta;

	int op = 0;
	while (1) {
		op = menu();

		if (op == 1) { //Abrir cuenta

			char buffer[50];
			int num_cuenta;
			cout << "Da nombre: "; cin.ignore(); cin.getline(buffer, 50);
			cout << "Da numero de cuenta: "; cin >> num_cuenta;

			char* nombre = new char[strlen(buffer) + 1];
			strcpy_s(nombre, strlen(buffer) + 1, buffer);

			cuenta c1(num_cuenta, nombre);
			lstCuenta.push_back(c1);



		}
		else if (op == 2) { //abrir prestamo
			int op2;
			//mostar cuentas

			for (int i = 0; i < lstCuenta.size(); i++) {
				cout << i << "\t" << lstCuenta[i].name << "\t" << lstCuenta[i].numero << endl;
			}

			cout << "seleccione la cuenta?: "; cin >> op2;
			int d, m, y;
			double cant;
			cout << "Dar Fecha?: "; cin >> d; cin >> m; cin >> y;
			cout << "Cantidad(euros ? )"; cin >> cant;

			prestamo p1(lstCuenta[op2], Fecha(d, m, y), cant);
			lstPrestamos.push_back(p1);
		


		}
		else if (op == 3) {
			int d, m, y;
			cout << "Fecha actual?: "; cin >> d; cin >> m; cin >> y;
			cout << "interes diario: " << INTERESDIARO << endl;
			cout << "Listado de prestamos y sus intereses: " << endl;
			cout << "===============================================" << endl;

			for (int i = 0; i < lstPrestamos.size(); i++) {
				int dias_now = 365 * y + 30 * m + d;
				int dias_prest = 365 * lstPrestamos[i].faper.y + 30 * lstPrestamos[i].faper.m + lstPrestamos[i].faper.d;
				int dif_dias = dias_now - dias_prest;

				cout << "dias: " << dif_dias << endl;
				cout << "interes: " << (INTERESDIARO / 100) * dif_dias * lstPrestamos[i].cantidad << endl;
				cout << "monto: " << lstPrestamos[i].cantidad << endl;
				cout << "Cuenta " << lstPrestamos[i].cta.name << "\t" << lstPrestamos[i].cta.numero << endl;
				cout << "-----------------------------------------" << endl << endl;

			}


		}
		else if (op == 4) {
			//grabar todo en fichero
			string f_name;
			cout << "Nombre para fichero? ";
			cin >> f_name;
			ofstream fout(f_name + ".txt");

			fout << "CUENTAS" << endl << "======================================================" << endl;

			for (int i = 0; i < lstCuenta.size(); i++) {
				fout << i << "\t" << lstCuenta[i].name << "\t" << lstCuenta[i].numero << endl;
			}

			fout << "PRESTAMOS" << endl << "=====================================================";
			fout << "Interes diario: " << INTERESDIARO << endl << endl;

			for (int i = 0; i < lstPrestamos.size(); i++) {
				fout << "Cuenta: " << "\t" << lstPrestamos[i].cta.name << "\t" << lstPrestamos[i].cta.numero << endl;
				fout << " Fecha: " << lstPrestamos[i].faper.d << "/" << lstPrestamos[i].faper.m << lstPrestamos[i].faper.y << endl;
				fout << "Monto: " << lstPrestamos[i].cantidad << endl;
				fout << "----------------------------------------------" << endl << endl;
			}

			fout.close();
		}
		else if (op == 5) {
			return 0;
		}

	}
}