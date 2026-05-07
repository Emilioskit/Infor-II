

class BankAcc { 

double balance; 
static double interest; //why static?
public:

	BankAcc(double b = 0) { balance = b; } //constructor

	void AddBalance(double quant); 
	void Payment(double amount); 
	void IntPaym();  //?
	double Balance() { return balance; } 
	bool Transfer(double amount, BankAcc& c); 
};