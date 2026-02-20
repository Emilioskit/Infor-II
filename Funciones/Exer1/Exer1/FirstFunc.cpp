#include "FirstFunc.hpp" //quotes for my headers
//no pragma once because this file is not included
// <> for standard or external libraries
#include <cmath>

double distance(double x1, double y1, double x2, double y2) {
	return(sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)));
}

