#include "Monede.h"


Monede::Monede()
{
	this->numar = 0;
	this->valoare = 0;
}

Monede::~Monede()
{
}

Monede::Monede(int numar, int valoare)
{
	this->numar = numar;
	this->valoare = valoare;

}

Monede::Monede(const Monede& m)
{
	this->numar = m.numar;
	this->valoare = m.valoare;
}

int Monede::getNumar()
{
	return this->numar;
}

int Monede::getValoare()
{
	return this->valoare;
}

void Monede::setNumar(int numar)
{
	this->numar = numar;
}

void Monede::setValoare(int valoare)
{
	this->valoare = valoare;
}

bool Monede::operator==(const Monede& p)
{
	return ((this->numar == p.numar) && (this->valoare == p.valoare));
}

Monede& Monede::operator=(const Monede& p)
{
	// TODO: insert return statement here
	this->setNumar(p.numar);
	this->setValoare(p.valoare);

	return *this;
}

ostream& operator<<(ostream& os, const Monede& s)
{
	// TODO: insert return statement here
	os << s.numar << " " << s.valoare << "\n";
	return os;
}

istream& operator>>(istream& is, Monede& s)
{
	// TODO: insert return statement here
	is >> s.numar >> s.valoare;
	return is;
}
