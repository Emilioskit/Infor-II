#include <iostream>
using namespace std;

struct Fecha { //DO IT NEED TO SET DEFAULT VALUES??
	int d;
	int m;
	int y;
};


struct cuenta {
	int numero; 
	char* name; //DEBE USAR MEMORIA DINAMICA NEW!!
};

struct prestamo {
	cuenta cta;
	Fecha faper;
	double cantidad;
};


int menu();