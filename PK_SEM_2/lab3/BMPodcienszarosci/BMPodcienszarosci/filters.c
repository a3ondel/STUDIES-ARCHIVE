#include "filters.h"


void ColortoGrayscale(PIXEL *ar,int x,int y)
{
	int tmp = 0;
	for (int i = 0; i < x*y; i++)
	{
		
		tmp = (ar[i].b + ar[i].g + ar[i].r)/3;
		ar[i].b = tmp;
		ar[i].g = tmp;
		ar[i].r = tmp;

	}

}