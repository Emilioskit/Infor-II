#include <iostream>
using namespace std;

double calcula(double alt, double dt) {

	double g = 9.81;
	double y = 0;
	double t = dt;

	do {
		y = alt - ((g * t * t) / 2.0);

		cout << "T:" << t*1000 << "(ms) \t" << "Altura: " << y << endl;
		t = t + dt;

	} while (y > 0);

	return y*1000;
	
	

	
}

int main() {
	double alt = 0;
	double dt = 0;
	cout << "altura: "; cin >> alt;
	cout << "dt: "; cin >> dt;

	dt = dt * 0.001;

	double time = calcula(alt, dt);
	cout << "------Resultado------";
	cout << "ha llegado al suelo a los " << time << "(ms)";


	return 0;
}