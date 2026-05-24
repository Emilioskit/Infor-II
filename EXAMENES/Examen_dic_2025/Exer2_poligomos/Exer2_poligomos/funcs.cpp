#include <iostream>
#include "funcs.hpp"
#include <fstream>



Punto::Punto(double a = 0, double b= 0): x(a), y(b){}
void Punto::Prt() {
	cout << x << " " << y << endl;
}

//must do to access private data!!
double Punto::getX() {
	return x;
}
double Punto::getY() {
	return y;
}


Poligono::Poligono(int n) : n(n), cont(0) {
	pv = new Punto[n]; //MUY IMPORTANTE TENER VALORES POR DEFAULT!!!!!!!
}
Poligono::~Poligono() {
	delete pv;
}

void Poligono::Add(Punto& p) { //pass a point and add it
	pv[cont] = p;
	cont++;

}

void Poligono ::Prt() {
	for (int i = 0; i < n; i++) {
		pv[i].Prt();
	}
}

double Poligono::Perimetro() {
	//recorremos puntos adyacentes y calculamos distancias

	//distancia del primero al ultimo
	double d = sqrt((pv[0].getX() - pv[n-1].getX()) * (pv[0].getX() - pv[n-1].getX())
		+ (pv[0].getY() - pv[n-1].getY()) * (pv[0].getY() - pv[n-1].getY()));


	for (int i = 0; i < n-1;i++) { //todas distancias excepto la del ultimo punto al primero
		
		double a = sqrt((pv[i].getX() - pv[i + 1].getX()) * (pv[i].getX() - pv[i + 1].getX())
						+ (pv[i].getY() - pv[i + 1].getY())* (pv[i].getY() - pv[i + 1].getY()));

		d = a + d;
	}
	return d;
}

double Poligono::Area() {
	double area = pv[n-1].getX()*pv[0].getY() - pv[n - 1].getY() * pv[0].getX();

	for (int i = 0; i < n - 1; i++) {
		area = area + pv[i].getX() * pv[i + 1].getY() - pv[i].getY() * pv[i + 1].getX();
	}

	return abs(area) * 0.5;
}

void Grabar(string name, double p, double a) {
	ofstream f(name);
	f << "perimetro: " << p << " area: " << a;
}