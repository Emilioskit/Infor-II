#include <iostream>
using namespace std;

#include "amigo.hpp"

int main() {
    int a, b;

    do {
        cout << "Dame el limite inferior: ";
        cin >> a;
        cout << "Dame el limite superior: ";
        cin >> b;

        if (a == b) break;

        // (opcional) si entran al revés, los ordeno
        if (a > b) { int tmp = a; a = b; b = tmp; }

        for (int i = a; i <= b; i++) {
            for (int j = a; j <= b; j++) { // evita duplicados
                if (amigo(i, j)) {
                    cout << i << " y " << j << " son amigos" << endl;
                }
            }
        }

    } while (true);

    return 0;
}
