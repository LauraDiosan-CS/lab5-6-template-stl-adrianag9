
#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Monede {
private:
	int numar;
	int valoare;
public:
	Monede();
	~Monede();
	Monede(int numar, int valoare);
	Monede(const Monede& m);
	int getNumar();
	int getValoare();

	void setNumar(int numar);
	void setValoare(int valoare);
	bool operator==(const Monede& p);

	Monede& operator=(const Monede& p);

	friend ostream& operator<<(ostream& os, const Monede& s);
	friend istream& operator>>(istream& is, Monede& s);

};