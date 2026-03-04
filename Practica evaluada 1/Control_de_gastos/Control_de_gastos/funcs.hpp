#pragma once;

struct Gasto
{
	char nombre[40]; //bus, comida, agua, movil, etc.
	double valor; //valor en euros
	int dia; //día del mes
};

void cargarGasto(Gasto gastos[], int& num);

void verGastos(Gasto gastos[], int num);
