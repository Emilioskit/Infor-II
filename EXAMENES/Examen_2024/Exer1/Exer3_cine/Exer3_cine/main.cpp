
#include <iostream>
#include <vector>
#include "funcs.hpp"
using namespace std;

int main() {
	vector <sala> lstSalas;
	int num_salas = 0;
	cout << "GESTION DE CINES" << endl;
	cout << "numero de salas: "; cin >> num_salas;

	for (int k = 0; k < num_salas; k++) {
		int f, a;
		char buffer[40];
		int h, m;
		double precio;
		cout << "Dar datos de las sala " << k;
		cout << "Numero de filas: "; cin >> f;
		cout << "Numero de asiento/fila: "; cin >> a;
		cout << "Pelicula? "; cin.ignore(); cin.getline(buffer, 40);
		cout << "Hora? "; cin >> h >> m;
		cout << "Precio? "; cin >> precio;
		
		//CREATE EMPTY ARRAY!!
		char s[20][30];
		for (int i = 0; i < 20;i++) {
			for (int j = 0; j < 30; j++) {
				s[i][j] = '0';
			}
		}

		sala sa(s, f, a, buffer, precio, hora(h, m));
		lstSalas.push_back(sa);
	}

	int op = 0;
	while (1) {
		op = menu();

		if (op == 1) {

			cout << "Listado de peliculas por sala: " << endl;
			for (int i = 0; i < lstSalas.size(); i++) {
				cout << "Sala " << i << endl<< "Pelicula: " << lstSalas[i].get_pelicula() << endl;
			}

			int op2 = 0;
			cout << "Que sala desea comprar: "; cin >> op2;

			lstSalas[op2].comprar();
			
		}
		else if (op == 2) {

			cout << "Listado de peliculas por sala: " << endl;
			for (int i = 0; i < lstSalas.size(); i++) {
				cout << "Sala " << i << endl << "Pelicula: " << lstSalas[i].get_pelicula() << endl;
			}
			
			int num_dev;
			cout << "De que sala desea devolver la entrada?: "; cin >> num_dev;
			lstSalas[num_dev].devolver();


		}
		else if (op == 3) {
			cout << "DINERO RECUADADO" << endl;
			int total_recaudacion = 0;
			for (int i = 0; i < lstSalas.size(); i++){
				total_recaudacion = total_recaudacion + lstSalas[i].prt(i);
			}

			cout << "total recuadado " << total_recaudacion << endl;
		}
		else if (op == 4) {
			return 0;
		}



	}
}