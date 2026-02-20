#include "funcs.hpp"
#include <iostream>
using namespace std;
// ----- FUNCTION DEFINITIONS -----

void prt(const mydata& data)
{
    for (int i = 0; i < (data.len); i++) {
        cout << data.x[i] << "\t" << data.y[i] << endl;
    }
}

double interp(const mydata& data, double x) {

    for (int i = 0; i < data.len - 1; i++) {
        if ((x >= data.x[i]) && (x <= data.x[i+1])) { //si esta en la mitad
            return(data.y[i] + (x-data.x[i])* ( (data.y[i+1]- data.y[i])
                                               /(data.x[i+1]- data.x[i]) ));
        }
    }
}

 