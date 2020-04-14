#pragma once
#include "RepoSTL.h"
#include "Produs.h"
#include "Monede.h"
#include <vector>
#include "Service.h"

class TestRepoProduse_Monede 
{
private:
	RepoSTL<Produs> repo_produse;
	RepoSTL<Monede> repo_monede;

	vector<Produs> produse_test;
	vector<Monede> monede_test;

	void test_repository_produse_elem_in_vector();

	void test_reporsitory_monede_elem_in_vector();
public:
	TestRepoProduse_Monede() {};

	void test_both();
};

class TestService_functions
{
private:
	RepoSTL<Produs> repo_produse;
	RepoSTL<Monede> repo_monede;

	void test_add_product();

	void test_delete_product();

	void test_update_product();

	void test_search_price_for_product_by_cod();

	void test_update_coin();
public:
	TestService_functions() {};

	void test_all();
};

class TestEntitys_set_and_get
{
private:
	void test_set_and_get_coins();

	void test_set_and_get_products();
public:
	TestEntitys_set_and_get() {};
	void test_both();
};