#include <iostream>
using namespace std;
#include "vehicle.hpp"
#include <vector>

int main()
{
    /*Car golf(2011, (char*)"BDA2456", 150);
    Car astra(2010, (char*)"ABZ2367", 110);

    Lorry Pegaso(2009, (char*)"AZT2345", 15);
    Lorry Iveco(2012, (char*)"CZT8953", 17);

    golf.display();
    astra.display();
    Pegaso.display();
    Iveco.display();

    cout << "End of vehicle list.." << endl;*/

    vector<Car*> vCar;
    vector<Lorry*> vLorry;

    int op = 0;
    int op2 = 0;
    while (1) {
        cout << "menu" << endl;
        cout << "1.add" << endl;
        cout << "2. show" << endl;
        cout << "3. exit" << endl;

        cout << "which choose?: "; cin >> op;

        if (op == 1) { //add
            cout << "1. Car or 2. Lorry?"; cin >> op2;

            if (op2 == 1) {
                int year;
                string plate;
                int hp;

                cout << "Year: ";
                cin >> year;

                cout << "Plate: ";
                cin >> plate;

                cout << "HP: ";
                cin >> hp;

                vCar.push_back(new Car(year, plate, hp));// USE NEW BECAUSE WE WANT DYNAMIC MEMORY!!
            }
            else {
                int year;
                string plate;
                int lmax;

                cout << "Year: ";
                cin >> year;

                cout << "Plate: ";
                cin >> plate;

                cout << "LMAX: ";
                cin >> lmax;

                vLorry.push_back(new Lorry(year, plate, lmax));// USE NEW BECAUSE WE WANT DYNAMIC MEMORY!!

            }
        }
        else if (op == 2) {//show
            for (auto it = vCar.begin(); it != vCar.end(); it++) {
                (*(*it)).display();
            }

            for (int i = 0; i < vLorry.size(); i++) {
                (*vLorry[i]).display();
            }
        }
        else {
            for (auto it = vCar.begin(); it != vCar.end(); it++) { //it is pointer to a the car pointer
                delete *it;
            }

            for (int i = 0; i < vLorry.size(); i++) {
                delete vLorry[i];
            }

            return 0;
        }
    }

}