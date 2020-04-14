#include <iostream>
#include "Console.h"
#include <math.h>

using namespace std;

void Console::options()
{
	cout << "1. Arata produse\n";
	cout << "2. Cumpara produs\n";
	cout << "3. Administrator\n";
	cout << "x. Exit\n";
}

void Console::administrator_options()
{
	cout << "1. Adauga produs\n";
	cout << "2. Sterge produs\n";
	cout << "3. Modifica produs\n";
	cout << "x. Exit\n";
}

int Console::console()
{
	float rest = this->get_available_rest();
	float current_balance = 0;
	while (true)
	{
		char option;
		this->options();
		cin >> option;
		if (option != '1' && option != '2' && option != 'x' && option != '3')
		{
			cout << "Optiunea alease este invalida, alegeti o optiune din lista data.\n";
		}
		else
		{
			if (option == 'x')
			{
				if (current_balance != 0)
				{
					cout << "Va mai asteptam! Tonomatul a eliberat " << current_balance << " lei \n";
				}
				return 0;
			}

			if (option == '1')
			{
				this->show_products();
			}

			if (option == '2')
			{
				current_balance = this->buy_product(current_balance);
			}
			if (option == '3')
			{
				this->administrator_commands();
			}
		}
	}
}

Console::Console()
{
}

Console::~Console()
{
}

Console::Console(const Service& service)
{
	this->service = service;
}

void Console::show_products()
{
	vector<Produs> produse = this->service.get_all_produse();

	int len_of_prods = produse.size();

	cout << "Produse valabile:\n";
	cout << "|| DENUMIRE - COD - PRET ||\n";

	for (int ind = 0; ind < len_of_prods;ind++)
	{
		cout << produse[ind].getNume() << " - " << produse[ind].getCod() << " - " << produse[ind].getPret() << "\n";
	}
	cout << "\n";
}

bool Console::verify_if_cod_of_prod_in_list(int cod)
{
	int len_of_prods = this->service.get_all_produse().size();

	for (int ind = 0;ind < len_of_prods;ind++)
	{
		if (this->service.get_all_produse()[ind].getCod() == cod)
		{
			return true;
		}
	}

	return false;
}

float Console::buy_product(float current_balance)
{
	float bancnota;
	int cod_prod;

	cout << " || balanta curenta: " << current_balance << " ||\n";
	if (current_balance == 0)
	{
		cout << "Introduceti bancnota: ";
		cin >> bancnota;
		current_balance = current_balance + bancnota;
	}

	cout << "Introduceti codul produsului pe care doriti sa il cumparati: ";
	cin >> cod_prod;
	if (!this->verify_if_cod_of_prod_in_list(cod_prod))
	{
		while (!this->verify_if_cod_of_prod_in_list(cod_prod))
		{
			cout << "Acest cod nu exista! Introduceti un alt cod:\n";
			cin >> cod_prod;
		}
	}
	Produs product = this->find_product_by_cod(cod_prod);
	float price_prod = this->service.search_price_for_product(product);
	while (true)
	{
		if (current_balance - price_prod >= 0)
		{
			cout << "Ati cumparat un produs!\n";
			cout << "Rest: " << current_balance - price_prod << "\n"; // rest
			this->modifiy_value_of_coins(this->get_available_rest(), current_balance - price_prod);
			current_balance = current_balance - price_prod;
			break;
		}
		else
		{
			cout << "Nu ati introdus suficienti bani in tonomat. Doriti sa introduceti o alta bancnota?\n";
			cout << "1. DA -- 2. NU\n";
			char second_operation;
			cin >> second_operation;
			if (second_operation == '1')
			{
				while (current_balance - price_prod < 0)
				{
					cout << " || balanta curenta: " << current_balance << " ||\n";
					cout << "Introduceti bancnota: ";
					cin >> bancnota;
					current_balance = current_balance + bancnota;
				}
				cout << "Ati cumparat un produs!\n";
				cout << "Rest: " << current_balance - price_prod << "\n"; // rest
				this->modifiy_value_of_coins(this->get_available_rest(), current_balance - price_prod);
				current_balance = current_balance - price_prod;
				break;
			}
			else
			{
				current_balance = 0;
				cout << "Bani au fost dati inapoi\n";
				break;
			}
		}
	}
	return current_balance;
}

void Console::administrator_commands()
{
	while (true)
	{
		char third_operation;
		this->administrator_options();
		cout << "Optiune aleasa: ";
		cin >> third_operation;
		if (third_operation != '1' && third_operation != '2' && third_operation != '3' && third_operation != 'x')
		{
			cout << "Optiunea alease este invalida, alegeti o optiune din lista data.\n";
		}
		else
		{
			if (third_operation == '1')
			{
				int cod, price;
				char* name;
				cout << "cod produs: ";
				cin >> cod;
				cout << "nume produs: ";
				name = new char[20];
				cin >> name;
				cout << "pret produs: ";
				cin >> price;
				if (!this->verify_if_cod_of_prod_in_list(cod))
				{
				Produs product = Produs(cod, name, price);
				this->service.add_product(product);
				}
				else
				{
					cout << "Codul introdus exista deja! Repetati operatia.\n";
				}
			}
			if (third_operation == '2')
			{
				int cod;
				cout << "codul produsului: ";
				cin >> cod;
				if (this->verify_if_cod_of_prod_in_list(cod))
				{
					Produs product = this->find_product_by_cod(cod);
					this->service.delete_product(product);
				}
				else
				{
					cout << "Codul dat nu exista, reincercati operatia cu un alt cod!\n";
				}
			}
			if (third_operation == '3')
			{
				int cod, new_cod, new_price;
				char* new_name;
				cout << " Daca nu doriti sa modificati ceva puneti {-1}\n";
				cout << "Codul produsului: ";
				cin >> cod;
				cout << "Codul nou: ";
				cin >> new_cod;
				new_name = new char[20];
				cout << "Numele nou: ";
				cin >> new_name;
				cout << "Pretul nou: ";
				cin >> new_price;
				if (this->verify_if_cod_of_prod_in_list(cod))
				{
					Produs old_product = this->find_product_by_cod(cod);
					if (new_cod == -1)
					{
						new_cod = old_product.getCod();
					}
					if (new_name[0] == '-')
					{
						new_name = old_product.getNume();
					}
					if (new_price == float(-1))
					{
						new_price = old_product.getPret();
					}
					Produs new_product(new_cod, new_name, new_price);
					this->service.update_produs(old_product, new_product);
				}
				else
				{
					cout << "Codul dat nu exista, reincercati operatia cu un alt cod!\n";
				}
			}
			if (third_operation == 'x')
			{
				break;
			}
		}
	}
}

float Console::search_price_for_product_by_cod(int cod)
{
	int len_of_prods = this->service.get_all_produse().size();
	for (int ind = 0;ind < len_of_prods;ind++)
	{
		if (this->service.get_all_produse()[ind].getCod() == cod)
		{
			return this->service.get_all_produse()[ind].getPret();
		}
	}
}

Produs Console::find_product_by_cod(int cod)
{
	int len_of_prods = this->service.get_all_produse().size();
	for (int ind = 0;ind < len_of_prods;ind++)
	{
		if (this->service.get_all_produse()[ind].getCod() == cod)
		{
			return this->service.get_all_produse()[ind];
		}
	}
}

float Console::get_available_rest()
{
	int len_of_coins = this->service.get_all_monede().size();
	float av_rest = 0;
	for (int ind = 0; ind < len_of_coins;ind++)
	{
		av_rest = av_rest + this->service.get_all_monede()[ind].getNumar() * service.get_all_monede()[ind].getValoare();
	}
	return av_rest;
}

void Console::modifiy_value_of_coins(float available_rest, float rest_to_give)
{
	int len_of_coins = this->service.get_all_monede().size();
	float rest_to_get_to = available_rest - rest_to_give;


	Monede old_moneda_cincizeci(this->service.get_all_monede()[0]);
	Monede old_moneda_zece(this->service.get_all_monede()[1]);
	Monede old_moneda_cinci(this->service.get_all_monede()[2]);
	Monede old_moneda_unu(this->service.get_all_monede()[3]);

	int coin_cincizeci = old_moneda_cincizeci.getNumar();
	int coin_zece = old_moneda_zece.getNumar();
	int coin_cinci = old_moneda_cinci.getNumar();
	int coin_unu = old_moneda_unu.getNumar();

	if (available_rest > rest_to_get_to)
	{
		while (available_rest != rest_to_get_to)
		{
			if (available_rest - 0.5 >= rest_to_get_to && coin_cincizeci >= 0)
			{
				coin_cincizeci--;
				available_rest = available_rest - 0.5;
			}
			if (available_rest - 0.1 >= rest_to_get_to && coin_zece >= 0)
			{
				coin_zece--;
				available_rest = available_rest - 0.1;
			}
			if (available_rest - 0.05 >= rest_to_get_to && coin_cinci >= 0)
			{
				coin_cinci--;
				available_rest = available_rest - 0.05;
			}
			if (available_rest - 0.01 >= rest_to_get_to && coin_unu >= 0)
			{
				coin_unu--;
				available_rest = available_rest - 0.01;
			}
			bool isEqual = fabs(available_rest - rest_to_get_to) <= 0.009;
			if (isEqual)
			{
				break;
			}
		}

		Monede new_coin_cincizeci(coin_cincizeci, old_moneda_cincizeci.getValoare());
		Monede new_coin_zece(coin_zece, old_moneda_zece.getValoare());
		Monede new_coin_cinci(coin_cinci, old_moneda_cinci.getValoare());
		Monede new_coin_unu(coin_unu, old_moneda_unu.getValoare());
		this->service.update_rest(old_moneda_cincizeci, new_coin_cincizeci);
		this->service.update_rest(old_moneda_zece, new_coin_zece);
		this->service.update_rest(old_moneda_cinci, new_coin_cinci);
		this->service.update_rest(old_moneda_unu, new_coin_unu);
	}
	else
	{
		cout << "Aparatul nu poate da atat de mult rest! Mai cumparati produse.\n";
	}
}
