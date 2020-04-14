00000// lab6-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RepoSTL.h"
#include "Test.h"
#include "Console.h"

using namespace std;

int main()
{
	TestRepoProduse_Monede test_repo;
	TestEntitys_set_and_get test_set_and_get;
	TestService_functions test_service_functions;

	test_service_functions.test_all();
	test_repo.test_both();
	test_set_and_get.test_both();

	RepoSTL<Produs> repo_prod("Produse.txt");
	RepoSTL<Monede> repo_monede("Monede.txt");

	Service service(repo_prod, repo_monede);

	Console console(service);
	
	console.console();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
