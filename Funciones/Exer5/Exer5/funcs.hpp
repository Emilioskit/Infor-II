#pragma once

// ---- - STRUCT---- -
struct mydata
{
    double x[20];
    double y[20]; // max length
    int len;
};

// ----- FUNCTION DECLARATIONS -----
void prt(const mydata& data); //pass by reference to not waste space and const to PROMISE to not change

double interp(const mydata& data, double x);