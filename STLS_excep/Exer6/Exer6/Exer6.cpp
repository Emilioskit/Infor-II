#include <iostream>
#include <vector>
using namespace std;

class vehicle {
    string brand;
    int hp;

public:
    /*vehicle(string bd = "BYD", int h = 100) {
        brand = bd;
        hp = h;
    }*/

    vehicle(string bd = "BYD", int h = 100) : brand(bd), hp(h) {}

    void prt() { cout << brand << "," << hp << endl; }
};

int main()
{
    vector<vehicle> lst; //create a vector that stores vehicles called lst

    vehicle v1("Toyota", 150); //define vehicle

    lst.push_back(v1); //add at the beggining??

    lst.push_back(vehicle("vw", 115));
    lst.push_back(vehicle("mazda", 200));
    lst.push_back(vehicle()); // add the default vehicle BYD 100!!
    lst.push_back(vehicle("fiat", 150));

    int len = lst.size();

    /*vector<vehicle>::iterator it1 = lst.begin();
    it1++;*/

    //IMPORTANT!!! auto is the same as (vector<vehicle>::iterator)
    for (auto it = lst.begin(); it != lst.end(); it++) {
        vehicle v = *it; //like dereference!
        v.prt();
    }

    int pos = 0;
    cout << "Which object to erase?";
    cin >> pos;

    cout << "Object to erase:";
    lst.at(pos).prt(); //.at the same as lst[pos]

    lst.erase(lst.begin() + pos); //it takes in an iterator not an index!!

    len = lst.size();
    cout << "\n-------- Other way..\n";

    for (int n = 0; n < len; n++) {
        vehicle v = lst[n];
        v.prt();
    }

    return 0;
}

//ITERATOR!!
//int arr[3] = { 1,2,3 };
//int* p = arr;
//
//vector<int> v = { 1,2,3 };
//auto it = v.begin();

//SAME AS POINTER KINDA!!!