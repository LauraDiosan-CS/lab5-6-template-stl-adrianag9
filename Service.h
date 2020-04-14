#pragma once

#include "RepoSTL.h"
#include "Produs.h"
#include "Monede.h"
#include <map>

using namespace std;

class Service
{
private:
	RepoSTL<Produs> repo_produse;
	RepoSTL<Monede> repo_monede;
	map<int, int> bancnote_adaugate;

public:
	void add_bancnota(int bancnota);

	Service() {};
	~Service()
	{
		bancnote_adaugate.clear();
	};
	Service(const RepoSTL<Produs>& produse, const RepoSTL<Monede>& monede);
	Service(const Service& s);

	float search_price_for_product(Produs product);

	vector<Produs> get_all_produse();
	vector<Monede> get_all_monede();

	void update_rest(Monede old_coin, Monede new_coin);

	void add_product(Produs product);

	void delete_product(Produs product);

	void update_produs(Produs old_product, Produs new_product);
};