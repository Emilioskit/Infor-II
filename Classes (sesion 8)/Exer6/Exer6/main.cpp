#include <iostream>
#include "bank.hpp"
using namespace std;

double BankAcc::interest = 0.01; //1% per month 

void main() { 
	BankAcc acc1(100), acc2(200); 
	cout << "Acc1:" <<acc1.Balance() ;
	cout << "Acc2:" <<acc2.Balance()<< endl; 
	
	/*acc1.IntPaym(); 
	acc2.IntPaym(); 

	acc1.Payment(50); 
	acc2.Payment(20);
	
	cout << "Acc1:"<<acc1.Balance()<< "Acc2:"<< acc2.Balance()<<endl;*/
	
	if (acc1.Transfer(80, acc2) == true) { 
		cout << "Trans. made" << endl; 
	} else {
		cout << "No balance.." << endl; 
	acc1.AddBalance(100); 
	}
	
	cout << "Acc1:" << acc1.Balance() << "Acc2:" << acc2.Balance() << endl;
}
