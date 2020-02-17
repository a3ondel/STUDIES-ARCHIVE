#include "tablica.h"
#include <algorithm>
#include <iostream>

Tablica::Tablica(int dl) 
{

	this->w = new Punkt[dl];
	this->dl = dl;

	for (int i=0; i < dl; i++)
		w[i] = { 0,0 };
}

Tablica::Tablica(float *x, float *y, int dl)
{

	this->w = new Punkt[dl];
	this->dl = dl;

	for (int i=0; i < dl; i++)
		w[i] = { x[i],y[i]};

}

Tablica::Tablica(Tablica &w_)
{
	this->w = new Punkt[w_.dl];
	this->dl = w_.dl;

	for (int i = 0; i < w_.dl; i++)
	{
		this->w[i] = w_.w[i];
	}

}

Tablica::~Tablica()
{
	delete [] this->w;
}

void Tablica::dodaj(Tablica &w_)
{
	int mindl = std::min(w_.dl, this->dl); //szukanie krotszej tablicy zeby z niej nie wypasc
	for (int i = 0; i < mindl; i++)
	{
		this->w[i].dodaj(w_.w[i]);
	}

}

bool Tablica::porownaj(Tablica &w_)
{
	if (this->dl != w_.dl)
		return false; //jezeli dlugosci sie roznia out

	for (int i = 0; i < this->dl; i++)
	{
		if (!(this->w[i].porownaj(w_.w[i])))
			return false;
	}

	
	return true;
}

void Tablica::drukuj()
{
	for (int i = 0; i < this->dl; i++)
	{
		w[i].drukuj();
		std::cout << std::endl;
	}
}
