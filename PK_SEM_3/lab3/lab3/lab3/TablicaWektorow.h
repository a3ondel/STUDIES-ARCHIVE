#pragma once
#include "Wektor.h"
class TablicaWektorow
{
protected:
	int dl;
	Wektor *w;

public:
	TablicaWektorow(int = 1); //wypelnia Wektor standardowy 
	TablicaWektorow(int, Wektor); //wypelnia wektorem
	TablicaWektorow(const TablicaWektorow & t1); //kopiujacy
	TablicaWektorow(const TablicaWektorow * t1); //kopiujacy
	void print();
	~TablicaWektorow();
	
	friend class TabWektorSort;

};

