#pragma once

#include "Service.h"

class Console
{
private:
	Service service;
public:

	void options();

	void administrator_options();

	int console();

	Console();
	~Console();
	Console(const Service& service);

	void show_products();

	bool verify_if_cod_of_prod_in_list(int cod);

	float buy_product(float current_balance);

	void administrator_commands();

	float search_price_for_product_by_cod(int cod);

	Produs find_product_by_cod(int cod);

	float get_available_rest();

	void modifiy_value_of_coins(float available_rest, float rest_to_give);

};