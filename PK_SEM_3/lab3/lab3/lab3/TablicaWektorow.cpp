#include "TablicaWektorow.h"



TablicaWektorow::TablicaWektorow(int dl)
{
	this->w = new Wektor[dl];
	this->dl = dl;
	for (int i = 0; i < dl; i++)
	{
		this->w[i] = { 0,0 };
	}

}

TablicaWektorow::TablicaWektorow(int dl_, Wektor v1)
{
	this->dl = dl_;
	this->w = new Wektor[dl_];

	for (int i = 0; i < dl_; i++)
	{
		w[i] = v1;
	}

}
TablicaWektorow::TablicaWektorow(const TablicaWektorow & t1)
{
	this->dl = t1.dl;
	this->w = new Wektor[this->dl];
	for (int i = 0; i < this->dl; i++)
	{
		this->w[i] = t1.w[i];
	}
}

TablicaWektorow::TablicaWektorow(const TablicaWektorow * t1)
{
	this->dl = t1->dl;
	this->w = new Wektor[this->dl];
	
	for (int i = 0; i < this->dl; i++)
	{
		this->w[i] = t1->w[i];
	}
}

void TablicaWektorow::print()
{
	for (int i = 0; i < dl; i++)
	{
		this->w[i].drukuj();
		std::cout << "Kierunek: " << w[i].kierunek << " dlugosc: " << w[i].dlugosc << std::endl;
	}

}


TablicaWektorow::~TablicaWektorow()
{
	if(this->w)
		delete[] this->w;
	this->w = nullptr;
}
