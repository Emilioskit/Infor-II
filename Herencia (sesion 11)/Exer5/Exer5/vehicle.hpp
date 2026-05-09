#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
	int year;
	string plate;

public:
	Vehicle(int y = 2000, string p ="AAA1234") : year(y), plate(p) {}
	void display() {
		cout << "Year: " << year << "Plate: " << plate<< endl;
	}

};


class Car : public Vehicle {
	int hp;
public:
	Car(int y = 2000, string p = "AAA1234", int horsepower = 65);
	void display();

};

class Lorry : public Vehicle {
	int lmax;
public:
	Lorry(int y = 2000, string p = "AAA1234", int lm = 10);
	void display();

};