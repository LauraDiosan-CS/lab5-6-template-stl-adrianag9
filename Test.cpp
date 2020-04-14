#include "Test.h"
#include "Service.h"
#include <cassert>
#include <iostream>

void TestRepoProduse_Monede::test_repository_produse_elem_in_vector()
{
	char* nume_1 = new char[strlen("CocaCola") + 1];
	strcpy_s(nume_1, strlen("CocaCola") + 1, "CocaCola");
	Produs p1(1, nume_1, 5);
	char* nume_2 = new char[strlen("PentaProt") + 1];
	strcpy_s(nume_2, strlen("PentaProt") + 1, "PentaProt");
	Produs p2(2, nume_2, 4);
	char* nume_3 = new char[strlen("Layz") + 1];
	strcpy_s(nume_3, strlen("Layz") + 1, "Layz");
	Produs p3(3, nume_3, 2);

	this->produse_test.push_back(p1);
	this->produse_test.push_back(p2);
	this->produse_test.push_back(p3);

	this->repo_produse.setFileName("TestProduse.txt");
	this->repo_produse.loadFromFile();

	int len_prod = this->repo_produse.getAll().size();

	for (int ind = 0; ind < len_prod; ind++)
	{
		assert(this->repo_produse.getAll()[ind] == this->produse_test[ind]);
	}
}

void TestRepoProduse_Monede::test_reporsitory_monede_elem_in_vector()
{
	Monede mon_one(100, 50);
	Monede mon_two(300, 10);
	Monede mon_three(200, 5);
	Monede mon_four(5000, 1);

	this->monede_test.push_back(mon_one);
	this->monede_test.push_back(mon_two);
	this->monede_test.push_back(mon_three);
	this->monede_test.push_back(mon_four);

	this->repo_monede.setFileName("TestMonede.txt");
	this->repo_monede.loadFromFile();

	int len_monede = this->repo_monede.getAll().size();

	for (int ind = 0; ind < len_monede; ind++)
	{
		assert(this->repo_monede.getAll()[ind] == this->monede_test[ind]);
	}
}

void TestRepoProduse_Monede::test_both()
{
	this->test_reporsitory_monede_elem_in_vector();
	this->test_repository_produse_elem_in_vector();
}

void TestEntitys_set_and_get::test_set_and_get_coins()
{
	Monede moneda(40, 50);

	assert(moneda.getNumar() == 40);
	assert(moneda.getValoare() == 50);

	moneda.setNumar(100);
	moneda.setValoare(30);

	assert(moneda.getNumar() == 100);
	assert(moneda.getValoare() == 30);
}

void TestEntitys_set_and_get::test_set_and_get_products()
{
	char* nume_1 = new char[strlen("CocaCola") + 1];
	strcpy_s(nume_1, strlen("CocaCola") + 1, "CocaCola");
	Produs p1(1, nume_1, 5);

	assert(p1.getCod() == 1);
	assert(p1.getNume() == "CocaCola");
	assert(p1.getPret() == 5);

	char* nume_2 = new char[strlen("Coca") + 1];
	strcpy_s(nume_2, strlen("Coca") + 1, "Coca");

	p1.setCod(3);
	p1.setNume(nume_2);
	p1.setPret(100);

	assert(p1.getCod() == 3);
	assert(p1.getNume() == "Coca");
	assert(p1.getPret() == 100);
}

void TestEntitys_set_and_get::test_both()
{
	void test_set_and_get_coins();
	void test_set_and_get_products();
}

void TestService_functions::test_add_product()
{
	this->repo_produse.setFileName("TestProduse.txt");
	this->repo_produse.loadFromFile();
	this->repo_monede.setFileName("TestMonede.txt");
	this->repo_monede.loadFromFile();

	Service service(repo_produse, repo_monede);

	assert(service.get_all_produse().size() == 3);

	char* nume = new char[strlen("Coca") + 1];
	strcpy_s(nume, strlen("Coca") + 1, "Coca");

	Produs produs(4, nume, 8);

	service.add_product(produs); 

	assert(service.get_all_produse().size() == 4);
}

void TestService_functions::test_delete_product()
{
	this->repo_produse.setFileName("TestProduse.txt");
	this->repo_produse.loadFromFile();
	this->repo_monede.setFileName("TestMonede.txt");
	this->repo_monede.loadFromFile();

	Service service(repo_produse, repo_monede);

	assert(service.get_all_produse().size() == 4);

	service.delete_product(service.get_all_produse()[3]);

	assert(service.get_all_produse().size() == 3);

}

void TestService_functions::test_update_product()
{
	this->repo_produse.setFileName("TestProduse.txt");
	this->repo_produse.loadFromFile();
	this->repo_monede.setFileName("TestMonede.txt");
	this->repo_monede.loadFromFile();

	Service service(repo_produse, repo_monede);


	char* nume = new char[strlen("Coca") + 1];
	strcpy_s(nume, strlen("Coca") + 1, "Coca");

	Produs produs(4, nume, 8);

	assert(service.get_all_produse()[3] == produs);

	char* new_nume = new char[strlen("Coccca") + 1];
	strcpy_s(new_nume, strlen("Coccca") + 1, "Coccca");

	Produs new_produs(99, new_nume, 3);

	service.update_produs(produs, new_produs);

	assert(service.get_all_produse()[3] == new_produs);

}

void TestService_functions::test_search_price_for_product_by_cod()
{
	this->repo_produse.setFileName("TestProduse.txt");
	this->repo_produse.loadFromFile();
	this->repo_monede.setFileName("TestMonede.txt");
	this->repo_monede.loadFromFile();

	Service service(repo_produse, repo_monede);

	Produs product = service.get_all_produse()[0];
	assert(service.search_price_for_product(product) == product.getPret());

}

void TestService_functions::test_update_coin()
{
	Service service(repo_produse, repo_monede);

	Monede moneda = service.get_all_monede()[0];

	Monede new_moneda(75, 25);

	service.update_rest(moneda, new_moneda);

	assert(new_moneda == service.get_all_monede()[0]);

	service.update_rest(new_moneda, moneda);

}

void TestService_functions::test_all()
{
	this->test_add_product();
	this->test_update_product();
	this->test_delete_product();
	this->test_search_price_for_product_by_cod();
	this->test_update_coin();
}
