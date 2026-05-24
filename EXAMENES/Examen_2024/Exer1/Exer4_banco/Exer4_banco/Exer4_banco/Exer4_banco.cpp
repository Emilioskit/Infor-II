#include <iostream>
using namespace std;
#include "funcs.hpp"
#include <ctime>
#include <fstream>


double cuenta::interes_base = 0.01; //STATIC DEFINED OUTSIDE!!!


int main() {
	srand(time(0));
	cuenta c1((char*)"Pedro", 1000);
	renta_mixta m1((char*)"Maria", 1000, 0.2, 0.05);
	renta_fija f1((char*)"Paco", 1000, 0.05);

	c1.prt();

	cout << c1.Gasto(200) << endl;
	cout << c1.Gasto(10000) << endl;
	cout << m1.Gasto(10) << endl;
	c1.prt();

	m1.transferencia(c1, 100);
	m1.historial(10);
	c1.prt();
	c1.historial(10);

	ofstream fout("Registro.txt");
	c1.Grabar(fout);

	cuenta c2;

	return 0;
}