#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int Menu();
int Menu2();
int SubMenu();
vector<string> LeerFichero(ifstream& fin);

void mostrarNombres(vector<string> lista);


// Añadir clase Fecha en un namespace

namespace EUR {
    class Fecha {
        int d, m, y;
    public:
        Fecha(int day = 0, int month= 0, int year = 0): d(day), m(month), y(year){}
        void prt() {
            cout << d << "/" << m << "/" << y;
        }
    };
}

namespace INT {
    class Fecha {
        int d, m, y;
    public:
        //should it not be inverse here??
        Fecha(  int year = 0, int month = 0, int day = 0) : d(day), m(month), y(year) {}
        void prt() {
            cout << y << "/" << m << "/" << d;
        }
    };
}

using Fecha = EUR::Fecha;

struct mantenimiento {

    Fecha fecha;
    string tarea;
};

class Central {
    string nombre_ID;
    double coste_base;           // Costes fijos de generación por MWh
protected:
    vector <double> potencia;    // En esta variable se almacena la potencia unitaria
    // de cada elemento de la Central
    vector <double> carga;       // En esta variable se almacena la carga de cada elemento
    // de la Central (0 = desactivado, 1= maxima potencia)
public:
    vector<mantenimiento> historialMantenimiento;
public:
    Central(string _nombre_ID = "", double _coste_base = 0) : nombre_ID(_nombre_ID), coste_base(_coste_base) {};
    void show_info();
    virtual ~Central();
    void get_name();
    double get_coste_base();
    double CalcularPotenciaTotal();
    double CalcularPotenciaMaxima();
    bool AjustarCargaPotenciaObjetivo(double p);
    void GrabarEnFichero(ofstream& fout);

    virtual double CalcularPrecioMWH();
    // GrabarEnFichero
    // Añada otras funciones si es necesario
};

class Eolica : public Central {
public:
    Eolica(string _nombre_ID = "", double _coste_base = 0) : Central(_nombre_ID, _coste_base) {};
    void AddTurbina(double p);
    double CalcularPrecioMWH();
    // Añada otras funciones si es necesario
};

class EolicaOffshore : public Eolica {
public:
    EolicaOffshore(string _nombre_ID = "", double _coste_base = 0) : Eolica(_nombre_ID, _coste_base) {};
    // Añada otras funciones si es necesario
    double CalcularPrecioMWH();
};

class Gas : public Central {
    double precio_gas;   // En € por tonelada
    double consumo_gas;  // En toneladas por MWh
public:
    Gas(string _nombre_ID = "", double _coste_base = 0, double _precio_gas = 0, double _consumo_gas = 0)
        : Central(_nombre_ID, _coste_base), precio_gas(_precio_gas), consumo_gas(_consumo_gas) {}
    void AddTurbinaGas(double p);
    // Añada otras funciones si es necesario
    double CalcularPrecioMWH();
};


