#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "funcs.hpp"


int Menu() {
    int opc = 0;

    while (opc < 1 || opc > 10) {

        system("cls");

        cout << "MENU" << endl;
        cout << "\t1. Mostrar fecha con distintos formatos" << endl;
        cout << "\t2. Leer nombres de fichero y mostrar por pantalla" << endl;
        cout << "\t3. Ordenar nombres leidos y mostrar por pantalla" << endl;
        cout << "\t4. Añadir Central" << endl;
        cout << "\t5. Añadir mantenimiento" << endl;
        cout << "\t6. Mostrar informacion" << endl;
        cout << "\t7. Grabar datos en fichero" << endl;
        cout << "\t8. Ajustar potencia de una central" << endl;
        cout << "\t9. Ajustar potencia del sistema" << endl;
        cout << "\t10. Salir" << endl;

        cout << "   Opcion: ";
        cin >> opc;
    }

    return opc;
}

int Menu2() {

    int opc = 0;

    while (opc < 1 || opc > 2) {

        cout << "\nSUB MENU" << endl;

        cout << "\t1. Añadir central Eolica" << endl;
        cout << "\t2. Añadir central de Gas" << endl;

        cout << "   Opcion: ";
        cin >> opc;

        cout << endl;
    }

    return opc;
}

int SubMenu() {
    int opc = 0;

    while (opc < 1 || opc > 3) {
        cout << "\nSUB MENU" << endl;
        cout << "\t1. Mostrar centrales Eolicas" << endl;
        cout << "\t2. Mostrar centrales de Gas" << endl;
        cout << "\t3. Mostrar todas" << endl;
        cout << "Opcion: ";
        cin >> opc;
    }

    return opc;
}

vector<string> LeerFichero(ifstream& fin) {
    string name;
    vector<string> Lista_nombres;

    while (getline(fin, name)) {
        Lista_nombres.push_back(name);
    }
    return Lista_nombres;
}

void mostrarNombres(vector<string> lista) {
    int n = lista.size();

    for (int i = 0; i < n; i++) {
        cout << lista[i] << endl;
    }
}

void Eolica::AddTurbina(double p) {
    potencia.push_back(p);
    carga.push_back(0);
}

void Gas::AddTurbinaGas(double p) {
    potencia.push_back(p);
    carga.push_back(0);

}

void Central::get_name() {
    cout << (*this).nombre_ID;
}

double Central::CalcularPotenciaMaxima() {

    double total = 0;
    for (int i = 0; i < potencia.size(); i++) {
        total = potencia[i] + total;
    }

    return total;
}

double Central::get_coste_base() {
    return coste_base;
}

double Central::CalcularPrecioMWH() {
    return (*this).get_coste_base();
    }

double Eolica::CalcularPrecioMWH() {
    return (*this).get_coste_base();
}

double EolicaOffshore::CalcularPrecioMWH() {
    return (*this).get_coste_base() * 1.5;
}

double Gas::CalcularPrecioMWH() {
    return (*this).get_coste_base() + precio_gas * consumo_gas;
}

void Central::show_info() {
    cout << nombre_ID << endl;
    cout << (*this).CalcularPotenciaMaxima() << endl;
    cout << CalcularPrecioMWH();
    //potencia de cada turbina y carga en %
    for (int i = 0; i < ((*this).potencia).size(); i++) {
        cout << ((*this).potencia)[i] << " | ";
    }
    cout << endl;

    for (int i = 0; i < ((*this).carga).size(); i++) {
        cout << (((*this).carga)[i])/100 << "% | ";
    }
    cout << endl;

    cout << "Mantenimiento: " << endl;
    //historial de mantenimiento
    for (int i = 0; i < ((*this).historialMantenimiento).size(); i++) {
        cout << "Mantenimiento " << to_string(i) << " : ";
        (((*this).historialMantenimiento[i]).fecha).prt(); //prt fecha
        cout << " "  << ((*this).historialMantenimiento[i]).tarea << endl;; //print tarea
    }


    cout << endl;


}

Central::~Central() {}

void Central::GrabarEnFichero(ofstream& fout) {
    fout << nombre_ID << endl;
    fout << (*this).CalcularPotenciaMaxima() << endl;
    fout << CalcularPrecioMWH();
    //potencia de cada turbina y carga en %
    for (int i = 0; i < ((*this).potencia).size(); i++) {
        fout << ((*this).potencia)[i] << " | ";
    }
    fout << endl;

    for (int i = 0; i < ((*this).carga).size(); i++) {
        fout << (((*this).carga)[i]) / 100 << "% | ";
    }
    fout << endl;

    fout << "Mantenimiento: " << endl;
    //historial de mantenimiento
    for (int i = 0; i < ((*this).historialMantenimiento).size(); i++) {
        fout << "Mantenimiento " << to_string(i) << " : ";
        (((*this).historialMantenimiento[i]).fecha).prt(); //prt fecha
        fout << " " << ((*this).historialMantenimiento[i]).tarea << endl;; //print tarea
    }


    fout << "=====================================================" << endl << endl;
}