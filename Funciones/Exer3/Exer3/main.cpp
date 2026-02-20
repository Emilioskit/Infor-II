//PB: obtaining the roots of a function using the midpoint method
#include <iostream>
using namespace std;
#include <math.h>

double fx(double);
double Midpoint(double a, double b, int max, int& num);
int main()
{
    double a, b;
    int num, max = 1000;

    cout << "Enter the interval to be evaluated, a b:";
    cin >> a >> b;
    //add the interval checking statements

    if (a > b) { //swap them if a > b
        double temp = a;
        a = b;
        b = temp;
    }

    double ZERO = 1e-9;

    if ((fx(a) < ZERO)) { //see if the root is one of a or b
        double root = a;
        cout << "The root is: " << root;
        return 0;
    } else if((fx(b) < ZERO)) {
        double root = b;
        cout << "The root is: " << root;
        return 0;
    }

    //check if the midpoint is in that interval to begin with
    if ((fx(a) * fx(b)) > 0) {
        cout << "There is no root in this interval";
        return 0;
    }

    double root = Midpoint(a, b, max, num);
    //Print the results on the screen
    cout << "The root is: " << root << ". It took " << num << " iterations.";
    return 0;
}

double Midpoint(double a, double b, int max, int& num) //NUM TO KEEP TRACK OF ITERATIONS,
{                                                       // REFERENCE TO MODIFY FROM INSIDE FUNCTION!!
    double m, ym, ZERO = 1e-9;
    num = 0;         //important
    //write the root calculating algorithm using the midpoint method
    while ((abs(a - b) > ZERO) && num < max) {
        m = (a + b) / 2;
        if ((fx(a) * fx(m)) < 0) { //midpoint is in [a,m]
            b = m;
        }
        else { //midpoint is in [m,b]
            a = m;
        }
        num++;
    }
    

    return m;
}

double fx(double x)   //x in radians
{
    double f = x - cos(x);    //roots between 0 and PI
    return f;
}
