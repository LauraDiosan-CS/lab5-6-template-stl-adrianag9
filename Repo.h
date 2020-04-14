#pragma once
#include <vector>
using namespace std;

template<class T>
class Repo {
private:
	vector<T> elemente;
public:

	Repo() {};

	~Repo() {
		this->elemente.clear();
	}

	void addElem(T c) 
	{
		this->elemente.push_back(c);
	};

	vector<T> getAll() {

		return this->elemente;
	};

	int getSize() {
		return this->elemente.size();
	};

	void stergere(T c) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c);
		if (!(it == this->elemente.end())) {

			this->elemente.erase(it);
		}
	};

	void update(T& c1, T& c2) {
		typename vector<T>::iterator it;

		it = find(this->elemente.begin(), this->elemente.end(), c1);
		if (!(it == this->elemente.end())) {

			*it = c2;
		}
	};


	void clear() {
		this->elemente.clear();
	}


	void setNumar(int pos, int newNumar) {

		this->elemente[pos].setNumar(newNumar);

	}


	T getElem(int i) {

		return this->elemente[i];

	}
};

