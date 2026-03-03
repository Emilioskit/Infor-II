#include <iostream>
#include "fucs.hpp"
using namespace std;



int main(){
	int n;
	cin >> n;
	int* vec = generaData(n);
	printData(vec, n);

	int nnum = 0;


	int* new_vec = comprimeData(vec, n, nnum);
	printData(new_vec, nnum);
	


	
	
	return 0;
}