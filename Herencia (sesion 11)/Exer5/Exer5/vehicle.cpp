#include "vehicle.hpp"

Car::Car(int y, string p, int horsepower) : Vehicle(y, p), hp(horsepower) {}
void Car::display() {
	cout << "Year: " << year << " Plate: " << plate << " Horsepower:" << hp<<endl;
}

Lorry::Lorry(int y, string p, int lm) : Vehicle(y, p), lmax(lm) {}

void Lorry::display() {
	cout << "Year: " << year << " Plate: " << plate << " Maximum load:" << lmax<<endl;
}