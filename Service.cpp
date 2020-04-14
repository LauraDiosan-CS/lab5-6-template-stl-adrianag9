#include "Service.h"

void Service::add_bancnota(int bancnota)
{
	if (bancnote_adaugate.count(bancnota) > 0)
	{
		int og_count = bancnote_adaugate[bancnota];

		bancnote_adaugate[bancnota] = og_count + 1;
	}
	else
	{
		bancnote_adaugate[bancnota] = 1;
	}
}

Service::Service(const RepoSTL<Produs>& produse, const RepoSTL<Monede>& monede)
{
	this->repo_produse = produse;
	this->repo_monede = monede;
}

Service::Service(const Service& s)
{
	this->repo_produse = s.repo_produse;
	this->repo_monede = s.repo_monede;
	this->bancnote_adaugate = s.bancnote_adaugate;
}

float Service::search_price_for_product(Produs product)
{
	return product.getPret();
}

vector<Produs> Service::get_all_produse()
{
	return this->repo_produse.getAll();
}

vector<Monede> Service::get_all_monede()
{
	return this->repo_monede.getAll();
}

void Service::update_rest(Monede old_coin, Monede new_coin)
{
	this->repo_monede.update(old_coin, new_coin);
	this->repo_monede.saveToFile();
}

void Service::add_product(Produs product)
{
	this->repo_produse.addElem(product);
	this->repo_produse.saveToFile();
}

void Service::delete_product(Produs product)
{
	this->repo_produse.stergere(product);
	this->repo_produse.saveToFile();
}

void Service::update_produs(Produs old_product, Produs new_product)
{
	this->repo_produse.update(old_product, new_product);
	this->repo_produse.saveToFile();
}

