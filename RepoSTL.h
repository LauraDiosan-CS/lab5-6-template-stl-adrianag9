#pragma once
#include "Repo.h"
#include <fstream>
#include <cstddef>
template<class T>

class RepoSTL : public Repo<T> {
private:
	char* fileName;
public:

	RepoSTL() : Repo<T>() {
		this->fileName = NULL;
	};

	~RepoSTL() {
		delete[] this->fileName;
	};

	RepoSTL(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();

	};

	void setFileName(const char* fileName) {

		if (this->fileName != NULL) {
			delete[] this->fileName;
		}
		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;

	};

	RepoSTL(const RepoSTL& r) {

		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}

	void loadFromFile() {

		if (this->fileName != NULL) {

			ifstream f(this->fileName);

			T elem;

			while (f>>elem) {
				Repo<T>::addElem(elem);

			}
			f.close();
		}
		else
			Repo<T>::clear();
	};

	void saveToFile() {

		if (this->fileName != NULL) {

			ofstream f(this->fileName);
			int n = Repo<T>::getSize();
			for (int i = 0; i <n; i++)
				f << Repo<T>::getElem(i);

			f.close();
		}
	};


	void addElem(T c) {
		Repo<T>::addElem(c);
		saveToFile();
	};

	void update(T &c1, T &c2) {
		Repo<T>::update(c1, c2);
		saveToFile();
	}


	void setNumberAtPos(int i, int newNumber) {
		Repo<T>::setNumar(i, newNumber);
	};


	vector<T> getAll() {
		return Repo<T>::getAll();
	};

	RepoSTL<T>& operator=(const RepoSTL<T>& repo)
	{
		this->setFileName(repo.fileName);
		this->loadFromFile();

		return *this;

	}

};