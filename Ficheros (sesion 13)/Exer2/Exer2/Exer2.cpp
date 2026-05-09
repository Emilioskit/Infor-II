#include <iostream>
using namespace std;
#include <fstream> //TO READ AND WRITE STUFF

int main() {
	char tmp[120];
	char filename[80];

	cout << "Name of file to read: ";
	cin >> filename;

	ifstream fin(filename); //open file to read
	if (!fin) { cout << "errror"; return 0; } //echeck fi ti opened 

	while (true) {
		fin.getline(tmp, 120); //>>> stops at newlines, this reads the whole line
		if (fin.eof()) break;
		cout << tmp << endl;
	}

	fin.close();

	return 0;
}

/*
FILES

#include <fstream>

ofstream fout("file.txt");   // write
ifstream fin("file.txt");    // read

if(!fout || !fin)            // check open
{
	return 0;
}

fout << x;                   // write
fin >> x;                    // read

fout.close();
fin.close();

FORMATTING

setw(n)          // width
fill('.')        // fill spaces
setf(ios::left)  // left align
unsetf(...)      // remove flag

STRINGS

strcmp(a,b)==0   // equal strings
*/