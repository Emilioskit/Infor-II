using namespace std;
#include <iostream>

class Punto {
	double x, y;
public:
	Punto(double, double);
	void Prt();
	double getX();
	double getY();
};

class Poligono {
	int n;
	int cont;
	Punto* pv; //array de puntos
public:
	Poligono(int n);//NUMERO DE VERTICES --> create the array?
	void Add(Punto& p); //pass an alias?
	void Prt();
	~Poligono();

	double Area();
	double Perimetro();
	
};

void Grabar(string, double, double);