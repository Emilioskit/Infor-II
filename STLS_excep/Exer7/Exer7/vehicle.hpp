using namespace std;
#include <string>

class date {
	int d, m, y;
	
public:
	date() {
		d = 0; m = 0; y = 0;
	}
	date(int day, int month, int year) {
		d = day; m = month; y = year;
	}
	void prt();
	void get();
	friend bool greaterthan(const date& d1,const date& d2);
};

class vehicle {
	string brand; //private
	date reg;
	int hp;
public:
	vehicle(string b, date rg, int hor) {
		brand = b; reg = rg; hp = hor;
	}
	void prt();
	date getReg();
	//more?

};