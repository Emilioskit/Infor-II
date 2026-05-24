#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include "funcs.hpp"
using namespace std;

int main() {
    vector<Eolica*> listEolicas; //Si lo desea puede utilizar vector<Eolica*>
    vector<Gas*> listGas;           //Si lo desea puede utilizar vector<Gas*>
    vector<Central*> list;           //Si lo desea puede utilizar vector<Planta*>
    int contE = 0;               // Contador de centrales eólicas
    int contG = 0;               // Contador de centrales de gas
    int cont = 0;                // Contador de centrales
    int opc2 = 0, opc = 0;
    bool flg = 0, flg2;
    vector<string> names;        // Vector con nombres disponibles para las centrales

    while (opc != 10) {
        opc = Menu();

        if (opc == 1) {
            cout << "\nUso de namespaces: " << endl;
            int d, y, m;
            cout << "Dia: "; cin >> d;
            cout << "Mes: "; cin >> m;
            cout << "Año: "; cin >> y;
            cout << "Fecha con formato europeo: ";

            Fecha f_eur(d, m, y);
            f_eur.prt();

            cout << "Fecha con formato internacional: ";
            INT::Fecha f_int(y, m, d);
            f_int.prt();

            system("pause");
        }

        if (opc == 2) {
            cout << "\nNombres leidos de fichero: " << endl;
            // Añadir código necesario

            ifstream fin("names.txt");
            names = LeerFichero(fin);
            fin.close();

            mostrarNombres(names);
            flg2 = 1; //para que anoto que ya lei los nombres???
            system("pause");
        }

        if (opc == 3 && flg2 == 1) {
            cout << "\nNombres ordenados alfabeticamente: " << endl;

            for (int i = 0;i < names.size() - 1; i++) {
                for (int j = i + 1; j < names.size();j++) {
                    if (names[j] < names[i]) {//switch
                        string temp = names[i];
                        names[i] = names[j];
                        names[j] = temp;
                    }
                }
            }

            mostrarNombres(names);

            system("pause");
        }

        if (opc == 4 && flg2 == 1) {
            cout << "\nAñadir central: " << endl;
            opc2 = Menu2();

            mostrarNombres(names); //mostramos los nombres

            int indx_numero;
            cout << "Selecciona un nombre (numero): "; cin >> indx_numero;



            if (opc2 == 1) { //eolica
                double coste;
                cout << "Coste Fijo (euros/MWh): "; cin >> coste;

                int flag_onshore;
                cout << "Es offshore? Si(1), no(0)?"; cin >> flag_onshore;

                Eolica* pointer = nullptr;
                contE++;
                cont++;

                if (flag_onshore == 1) {//si es onshore
                    pointer = new Eolica("EOLICA " + names[indx_numero], coste);


                }
                else if (flag_onshore == 0) {// si es OFFshore
                    pointer = new EolicaOffshore("EOLICA OFFSHORE " + names[indx_numero], coste);
                    //works because eolica offshore is child

                }

                listEolicas.push_back(pointer);
                list.push_back(pointer);
                //borramos el nombre escogido
                names[indx_numero].clear();

                while (1) {
                    double potencia;
                    cout << "Potencia de turbina eolica(MW): ";
                    cin >> potencia;

                    pointer->AddTurbina(potencia);

                    int continuar;
                    cout << "Anadir otra turbina? Si(1) No(0)"; cin >> continuar;

                    if (continuar == 0) {

                        break;
                    }
                }


            }
            else if (opc2 == 2) { //gas

                //ESCOGER NOMBRE, ya fue hecho antes


                double coste;
                double consumo;
                double precio_gas;
                cout << "Coste Fijo (euros/MWh): "; cin >> coste;
                cout << "Consumo de gas??: "; cin >> consumo;
                cout << "Precio gas??: "; cin >> precio_gas;



                //creamos pointer y guardamos ese mismo en dos lugares distintos
                Gas* pointer = new Gas("Gas " + names[indx_numero], coste, consumo, precio_gas); //!NEW do not forget!!
                listGas.push_back(pointer);
                list.push_back(pointer);
                //borramos el nombre que ya usamos
                names[indx_numero].clear();

                cont++; //Im not sure this is neccesary because im using vector but just in case
                contG++;

                while (1) {
                    double potencia;
                    cout << "Potencia de turbina de gas: "; cin >> potencia;
                    pointer->AddTurbinaGas(potencia);

                    int continuar;
                    cout << "Anadir otra turbina? Si(1) No(0)"; cin >> continuar;

                    if (continuar == 0) {

                        break;
                    }
                }

            }


            system("pause");
        }

        if (opc == 5) {

            cout << "\nAñadir mantenimiento" << endl;
            //MOSTRAR TODAS LAS CENTRALES QUE TENEMOS
            for (int i = 0; i < list.size(); i++) {
                cout << to_string(i) << "\t";
                list[i]->get_name(); cout << endl;
            }
            //choose one

            int indx_man;
            cout << "Choose which one: "; cin >> indx_man;

            int d, m, y;
            string comentario;
            cout << "Dime dia"; cin >> d;
            cout << "Dime mes"; cin >> m;
            cout << "Dime anno"; cin >> y;
            cout << "Dime tarea realizada: ";
            cin.ignore();
            getline(cin, comentario);


            mantenimiento man(Fecha(d, m, y), comentario);
            //anadir mantimieno a planta respectiva
            ((*list[indx_man]).historialMantenimiento).push_back(man);




            system("pause");
        }

        if (opc == 6) {
            cout << "\nMostrar informacion de centrales" << endl;
            // Añadir código necesario

            int opc3 = SubMenu();

            if (opc3 == 1) { //eolicas

                for (int i = 0; i < listEolicas.size(); i++) {
                    listEolicas[i]->show_info();
                }

            }
            else if (opc3 == 2) {//gas
                for (int i = 0; i < listGas.size(); i++) {
                    listGas[i]->show_info();
                }

            }
            else if (opc3 == 3) {//todas
                for (int i = 0; i < list.size(); i++) {
                    list[i]->show_info();
                }

            }
            system("pause");
        }

        if (opc == 7) {
            cout << "\nGrabar datos: " << endl;

            //graba datos de TODAS!! 
            string nombre_f;
            cout << "Nombre del fichero?"; cin >> nombre_f;
            ofstream fout(nombre_f + ".txt");
            for (int i = 0; i < list.size(); i++) {
                list[i]->GrabarEnFichero(fout);
            }
            fout.close();
            // Añadir código necesario
            system("pause");
        }

        if (opc == 8) {
            cout << "\nAjustar potencia de una Central" << endl;
            // Añadir código necesario
            system("pause");
        }

        if (opc == 9) {
            cout << "\nAjustar potencia del sistema" << endl;
            // Añadir código necesario
            system("pause");
        }

        if (opc == 10) {
            cout << "\nSalir" << endl;
            // Añadir código necesario
        }
    }

    return 0;

}
