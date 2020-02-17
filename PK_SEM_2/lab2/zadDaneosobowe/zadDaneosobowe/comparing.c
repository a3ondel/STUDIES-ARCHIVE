#include "comparing.h"
#include <string.h>

//funkcja porownujaca po id pod qsort
int comparetorid(const DaneOsobowe *a, const DaneOsobowe * b)
{
	return a->id - b->id; 
}

//funkcja porownujaca po imieniu pod qsort
int comparetorimie(const DaneOsobowe *a, const DaneOsobowe * b)
{
	return strcmp(a->imie, b->imie);
}