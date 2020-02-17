#pragma once
#include "punkt.h"

class Tablica
{
	Punkt * w; //wskaznik tablicy
	int dl; // dlugo�� Tablicy

public:

	Tablica(int dl = 0); // tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	Tablica(Tablica &w_); //inicjalizacja za pomoc� Tablicy w_
	Tablica(float *x, float *y, int dl); // inicjalizacja tablicy  punkt�w  tablicami x -�w i y -�w

	~Tablica();

	void dodaj(const Tablica &w_);// dodaje do siebie Tablice w_
	bool porownaj(const Tablica &w_);// porownnaie z Tablica w_;

	void operator=(const Tablica & w_);
	bool operator==(const Tablica & w_);
	friend std::ostream & operator<<(std::ostream & output, const Tablica & w);
	Punkt & operator[](int index);
	Tablica(const std::string &nazwa);
	

};