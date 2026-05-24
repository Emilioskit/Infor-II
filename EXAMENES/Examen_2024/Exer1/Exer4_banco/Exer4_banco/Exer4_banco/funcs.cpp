#include <iostream>
using namespace std;
#include "funcs.hpp"
#include <string>
#include<cstdlib>
#include <ctime>

cuenta::cuenta(const char* nombre, double saldo_ini) : cont(0) {
	strcpy_s(titular, 20, nombre);
	saldo = new double[100]; //asignar dimension de 100 a saldo
	saldo[0] = saldo_ini;
	for (int i = 1; i < 100; i++) {
		saldo[i] = 0;
	}
	
}

cuenta::~cuenta() {
	delete[] saldo;
}

renta_mixta::renta_mixta(const char* nombre, double saldo_ini, double int_fijo, double prop_v)
	: cuenta(nombre, saldo_ini), interes_fijo(int_fijo), prop_variable(prop_v) {}

renta_fija::renta_fija(const char* nombre, double saldo_ini, double int_fijo) :
	renta_mixta(nombre, saldo_ini, int_fijo, 0) {}

bool cuenta::Gasto(double x) {
	if (x > 0 && saldo[cont] >=x) {
		saldo[cont + 1] = saldo[cont] - x;
		cont++;
		return true;
	}
	else {
		return false;
	}
}

bool renta_fija::Gasto(double x) {
	return false;
}

bool renta_mixta::Gasto(double x) {
	return false;
}

void cuenta::prt() {
	cout << "Titular: " << titular << "\t" << "Saldo " << saldo[cont] << endl;
}

void cuenta::historial(int num) {
	cout << "Titular: " << titular << endl;
	if (num > cont ) {
		for (int i = cont; i >= 0; i--) {
			cout << i << ": \t" << saldo[i] << endl;
		}
	}
	else{ //mostramos los que nos piden
		for (int i = cont; i >= num; i--) {
			cout << i << ": \t" << saldo[i] << endl;
		}

	}
}

bool cuenta::transferencia(cuenta& c, double cant) {//cuenta de destino
	if (saldo[cont] < cant) { //si tengo menos plata que lo que me piden
		return false;
	}
	else {
		//no puedo usar gasto porque renta_mixta y fija me harian return false
		saldo[cont + 1] = saldo[cont] - cant;
		cont++;

		//como le anado plata a la otra cuenta??
		
		c.saldo[c.cont + 1] = c.saldo[c.cont] + cant;
		c.cont++;

		return true;
	}
}

double cuenta::get_intereses() {
	return interes_base;
}

double renta_mixta::get_intereses() {

	double interes_variable = -0.5 + (double)rand() / RAND_MAX * (1.5 - (-0.5));
	double intereses_fijos = interes_fijo + get_interes_base(); //NECESITO PODER ACCEDER A INTERES BASE
	return (1 - prop_variable) * intereses_fijos + (prop_variable)*interes_variable;
}

double renta_fija::get_intereses() {
	double intereses_fijos = get_interes_fijo() + get_interes_base(); //NECESITO PODER ACCEDER A INTERES BASE
	return  intereses_fijos;
}

double* cuenta::Simular(int n) {
	double* res = new double[n];
	res[0] = saldo[cont]; //EMPEZAMOS CON LO QUE TENEMOS EN LA CUENTA AHORITA

	for (int i = 1; i < n; i++) {//doy n vueltas
		res[i] = res[i-1] + get_intereses() * saldo[i-1];
	}

	return res;
}

void cuenta::Grabar(ofstream& fout) {
	fout << "num movimientos: " << cont << endl;
	for (int i = cont; i >= 0; i--) {
		fout << i << ": \t" << saldo[i] << endl;
	}

	fout.close();
}
cuenta cuenta::Leer(istream& fin) {
	int num;
	fin >> num;//num of saldos to read
	
	for (int i = 0; i < num;i++) {
		fin >> saldo[i];
		cont++;
	}
	
	return *this;
}