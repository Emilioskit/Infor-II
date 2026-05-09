// DiscoOut.cpp

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    char name[80], filename[80];
    int age;

    cout << "Name of the file to write: ";
    cin >> filename;

    ofstream fout(filename); //OPEN FILE!!

    if (!fout) //if it did not open for some reason
    {
        cout << "Error.." << endl;
        return 0;
    }

    fout.fill('.');//???

    while (true)
    {
        cout << "Name(end->exit): ";
        cin >> name;

        if (strcmp(name, "end") == 0) //if I write end, it stops writting
            break;

        cout << "Age: ";
        cin >> age;

        fout.setf(ios::left);
        fout << setw(15) << name;
        fout.unsetf(ios::left);
        fout << setw(4) << age << endl;
    }

    fout.close();

    cout << "Data stored in: " << filename << endl;

    return 0;
}