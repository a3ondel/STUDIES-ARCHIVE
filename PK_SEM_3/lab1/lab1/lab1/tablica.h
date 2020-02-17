#pragma once
#include "punkt.h"

class Tablica
{
	Punkt * w;
	int dl; // dlugo�� Tablicy
public:
	Tablica(int dl = 0); // tworzy Tablice o zadanej d�ugo�ci i wype�nia punktami (0,0)
	Tablica(Tablica &w_); //inicjalizacja za pomoc� Tablicy w_
	Tablica(float *x, float *y, int dl); // inicjalizacja tablicy  punkt�w  tablicami x -�w i y -�w

	~Tablica();

	void dodaj(Tablica &w_);// dodaje do siebie Tablice w_

	bool porownaj(Tablica &w_);// porownnaie z Tablica w_;
	void drukuj();
};
