#include "Wieza.h"
#include <iostream>

bool Wieza::set(Szachownica * s_, int x_, int y_)
{
	s = s_;
	if (Figura::set( x_, y_,this))
	{
		Figura::set(x_, y_, 'W');
		return true;
	}
	return false;
}

void Wieza::range() 
{
	if(this->s->sz[x][y])
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			if (i == y || j == x)
				this->s->wiz[j][i] = 'W';
	}
}
