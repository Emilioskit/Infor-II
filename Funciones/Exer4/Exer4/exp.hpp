#pragma once


double factorial(double a); //MUST BE DOUBLE OR IT OVERFLOWS AT 13!
//two functions that find value of e^x
double Exp(double x, double num); //stops at NUM interations
double Exp(double x, double Error, int& num); //stops at error and printss NUM iterations it took
