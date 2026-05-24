#include <fstream>
class cuenta {
private:
	static double interes_base;
	char titular[20]; //nombre del titutar
	virtual double get_intereses();
protected:
	double* saldo; //evolucion del saldo segun se realizan movimientos
	int cont;
	double get_interes_base() {
		return interes_base;
	}
	
public:
	virtual bool Gasto(double x);
	cuenta(const char* nombre = "none", double saldo_ini = 0);
	~cuenta();
	void prt();
	void historial(int num);
	bool transferencia(cuenta& c, double cant);
	double* Simular(int n); //para que devuleva array de deouble
	void Grabar(ofstream& fout);
	cuenta Leer(istream& fin);
};

class renta_mixta:public cuenta {
private:
	double interes_fijo;
	double prop_variable;
	double get_intereses();
protected:
	double get_interes_fijo() {
		return interes_fijo;
	}
public: 
	renta_mixta(const char* nombre = "none", double saldo_ini=0, double int_fijo=0, double prop_v=0);
	bool Gasto(double x);
	
};

class renta_fija : public renta_mixta {
private:
	double get_intereses();
	
public:
	renta_fija(const char* nombre = "none", double saldo_ini=0, double int_fijo=0);
	bool Gasto(double x);
};