#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Produs {
private:
	int cod;
	char* nume;
	int pret;
public:
	Produs();
	~Produs();
	Produs(int cod, char* nume, float pret);
	int getCod();
	char* getNume();
	float getPret();
	Produs(const Produs& p);

	void setCod(int  cod);
	void setNume(char* nume);
	void setPret(float pret);

	bool operator==(const Produs& p);

	Produs& operator=(const Produs& p);

	friend ostream& operator<<(ostream& os,const Produs& s);
	friend istream& operator>>(istream& is, Produs& s);

};