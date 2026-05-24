#include <iostream>
#include <string>
using namespace std;

class hora {
private:
	int hh;
	int min;
public:
	hora(int hora, int min) : hh(hora), min(min) {}
	void prt();
};

class sala {
private:
	char asiento[20][30]; // "0" libre ( MAXX!! 20 filas y 30 asientas por fila)
	int fils, cols;
	char pelicula[40];
	double precio;
	hora h;
public:
	sala(char a[20][30], int fils, int cols, const char* peli, double precio, hora ho);

	char* get_pelicula();
	double prt(int cont);
	void comprar();
	void devolver();
	double recaudado();

};

int menu();