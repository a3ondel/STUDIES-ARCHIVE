#include "tablica.h"
#include <algorithm>
#include <iostream>
#include <fstream>

Tablica::Tablica(int dl) 
{
	Punkt tmp(0, 0);
	this->w = new Punkt[dl];
	this->dl = dl;

	for (int i=0; i < dl; i++)
		w[i] = tmp;
}

Tablica::Tablica(float *x, float *y, int dl)
{

	this->w = new Punkt[dl];
	this->dl = dl;
	
	
	for (int i = 0; i < dl; i++)
	{
		
		
		w[i] = {x[i],y[i ]};
	}
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

void Tablica::dodaj(const Tablica &w_)
{
	int mindl = std::min(w_.dl, this->dl); //szukanie krotszej tablicy zeby z niej nie wypasc
	for (int i = 0; i < mindl; i++)
	{
		this->w[i].dodaj(w_.w[i]);
	}

}

bool Tablica::porownaj(const Tablica &w_)
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

void Tablica::operator=(const Tablica & w_)
{
	if (w_.w == this->w)
		return;

	if (this->dl != w_.dl)
	{
		this->dl = w_.dl;
		delete[] this->w;
		this->w = new Punkt[this->dl];
	}

	for (int i = 0; i < this->dl; i++)
	{
		this->w[i] = w_.w[i];
	}

}
bool Tablica::operator==(const Tablica & w_)
{
	if (this->w == w_.w)
		return true;

	if (this->dl != w_.dl)
		return false; //jezeli dlugosci sie roznia out

	for (int i = 0; i < this->dl; i++)
	{
		if (!(this->w[i] == w_.w[i]))
			return false;
	}
	return true;
}

std::ostream & operator<<(std::ostream & output, const Tablica & w)
{
	{
		for (int i = 0; i < w.dl; i++)
		{
			output << w.w[i] << std::endl;
		}
		return output;
	}
}

Punkt & Tablica::operator[](int index)
{
	return this->w[index];
}

Tablica::Tablica(const std::string &nazwa)
{

	std::ifstream plik(nazwa);
	if (plik)
	{
		int liczba_pkt = 0;
		plik >> liczba_pkt;
		this->dl = liczba_pkt;
		this->w = new Punkt[liczba_pkt];

		float tmp_X = 0, tmp_Y = 0;

		for (int i = 0; i < liczba_pkt; i++)
		{
			plik >> tmp_X >> tmp_Y;

			this->w[i] = { tmp_X,tmp_Y };
		}
		plik.close();
	}
}

