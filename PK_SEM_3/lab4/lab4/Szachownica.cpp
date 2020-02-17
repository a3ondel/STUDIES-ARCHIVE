#include "Szachownica.h"
#include "Figura.h"
#include<iostream>

using std::cout;
using std::endl;

void Szachownica::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			wiz[j][i] = '.';
			sz[j][i] = nullptr;
		}
}



Szachownica::Szachownica()
{
	clear();
}

void Szachownica::showRange()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
			if(sz[j][i])
				sz[j][i]->range();
			
		}
	}
	this->display();
}

void Szachownica::display()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << wiz[j][i];
		cout << endl;
	}
}
