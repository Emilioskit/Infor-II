#include <iostream>
#include "funcs.hpp"
using namespace std;

int main() {
	cout << "**Pol: Area y Perimetro";

	while (1) {
		int vert;
		cout << "Numero de vertices? "; cin >> vert;
		Poligono pol(vert);

		for (int i = 0; i < vert; i++) {
			int x; int y;
			cout << "x, y?: "; cin >> x >> y;
			Punto p(x, y);
			pol.Add(p);
		}

		int per = pol.Perimetro();
		int area = pol.Area();
		cout << "Perimetro: " << per << endl;
		cout << "Area: " << area << endl;
		
		string name;
		cout << "Name of save file?: "; cin >> name;
		Grabar(name, per, area);

		int op;
		cout << "1 to continue and 0 to stop"; cin >> op;

			if (op == 0) {
				return 0;
		}	
	}
}