#include "bank.hpp"
#include <iostream>

void BankAcc::AddBalance(double quant) {
	balance += quant;
}

void BankAcc::Payment(double amount) {
	balance -= amount;
}

void BankAcc::IntPaym() {//just take away one month of interest I image
	balance = balance* (1-interest);
}


bool BankAcc::Transfer(double amount, BankAcc& c) { //from to c

	//comprobar que tiene plata suficiente???
	if (balance >= amount) {

		c.AddBalance(amount);
		(*this).Payment(amount);
		return true;
	}
	else {
		return false;
	}
}