#include "Produs.h"
#include <cstddef>
#include <string>

Produs::Produs()
{
	this->cod = 0;
	this->nume = NULL;
	this->pret = 0.0;
}

Produs::~Produs()
{
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
}

Produs::Produs(int cod, char* nume, float pret)
{
	this->cod = cod;

	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);

	this->pret = pret;
}

int Produs::getCod()
{
	return this->cod;
}

char* Produs::getNume()
{
	return this->nume;
}

float Produs::getPret()
{
	return this->pret;
}

Produs::Produs(const Produs& p)
{
	this->cod = p.cod;
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	this->pret = p.pret;

}

void Produs::setCod(int cod)
{
	this->cod = cod;
}

void Produs::setNume(char* nume)
{
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	if (nume != NULL) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
		this->nume = NULL;

}

void Produs::setPret(float pret)
{
	this->pret = pret;
}

bool Produs::operator==(const Produs& p)
{
	return ((this->cod == p.cod) && (strcmp(this->nume, p.nume) == 0) && (this->pret == p.pret));
}

Produs& Produs::operator=(const Produs& p)
{
	this->setCod(p.cod);
	this->setNume(p.nume);
	this->setPret(p.pret);

	return *this;
}

ostream& operator<<(ostream& os, const Produs& s)
{
	// TODO: insert return statement here
	os << s.cod << " " << s.nume << " " << s.pret <<"\n";
	return os;
}

istream& operator>>(istream& is, Produs& s)
{
	if (s.nume == NULL)
		s.nume = new char[20];
	is >> s.cod >> s.nume >> s.pret;
	return is;
	// TODO: insert return statement here
}
