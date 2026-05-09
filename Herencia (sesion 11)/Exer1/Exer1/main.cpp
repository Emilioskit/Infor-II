#include <iostream>
#include "Employee.hpp"

using namespace std;

int main() {
    //Employee Rafa("Rafa");
    //Manager Mario("Mario");
    //Worker Anton("Anton");
    //Officer Luis("Luis");
    //Technician Pablo("Pablo");

    //// The type of object determines the function that is called
    //cout << "With object names:\n" << endl;

    //cout << Rafa.GetName();
    //Rafa.print_position();

    //cout << Mario.GetName();
    //Mario.print_position();

    //cout << Anton.GetName();
    //Anton.print_position();

    //cout << Luis.GetName();
    //Luis.print_position();

    //cout << Pablo.GetName();
    //Pablo.print_position();


    Employee Rafa("Rafa", 850);
    Manager Mario("Mario", 2500);
    Worker Anton("Anton", 1250);
    Officer Luis("Luis", 1500);
    Technician Pablo("Pablo", 1750);

    Rafa.prt();
    Mario.prt();
    //.. print to console the rest of the objects

	return 0;
}