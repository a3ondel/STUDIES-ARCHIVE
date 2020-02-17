#include "Goniec.h"
#include<iostream>
#include <cmath>

void Goniec::range()
{
	if (s->sz[x][y])
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i==(j-y+x)||i==(-j+y+x))
					s->wiz[j][i] = 'G';
		}
}

bool Goniec::set(Szachownica * s_, int x_, int y_)
{
	s = s_;
	if (Figura::set(x_, y_, this))
	{
		Figura::set(x_, y_, 'G');

		return true;
	}
	return false;
}
