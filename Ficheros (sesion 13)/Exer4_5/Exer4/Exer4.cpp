#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


struct Point {
	double x, y;
};

class Data {
	vector<Point> vec; //?

public:
	void Push(Point& p) { vec.push_back(p); } //Data has a vector and im adding a new point p to it
	void Prt() {
		int len = vec.size();
		for (auto i = 0; i < len; i++) {
			cout << showpoint << vec[i].x << " " << vec[i].y << endl;
		}
	}

	void Save2Disk(ofstream& f) {
		int len = vec.size();
		for (auto i = 0; i < len; i++) {
			f << showpoint << vec[i].x << " " << vec[i].y << endl;
		}
	}

    void Clear() {
        vec.clear();
    }
};

int main()
{
    int op = 0;
    Data d;

    while (true)
    {
        cout << "1. introduce data\n";
        cout << "2. write data to disk\n";
        cout << "3. Read data and continue introducing data";
        cout << "4. exit\n";

        cout << "choose? ";
        cin >> op;

        if (op == 1)
        {
            double x, y;
            cout << "point?: ";
            cin >> x >> y;

            Point p; //assign like this because no constructor
            p.x = x;
            p.y = y;

            d.Push(p);
        }
        else if (op == 2)
        {
            string name;
            cout << "filename? ";
            cin >> name;

            ofstream f(name);

            if (!f)
            {
                cout << "Error opening file\n";
                return 0;
            }

            d.Save2Disk(f);
            f.close();

            d.Clear();
        }
        else if (op == 3) //read data and continue introducing
        {
            d.Clear(); //clear variable at start!!

            string name;
            cout << "Filename to read?: ";
            cin >> name;

            ifstream fin(name);
            if (!fin) { break; }

            while (true) {
                double x, y;
                fin >> x >> y;
                if (fin.eof()) { break; }

                Point p;
                p.x = x;
                p.y = y;

                d.Push(p);
            }
            
        }
        else {
            break;
        }
    }

    return 0;
}