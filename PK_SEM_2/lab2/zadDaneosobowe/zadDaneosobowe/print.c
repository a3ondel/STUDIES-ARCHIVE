#include "print.h"

//funkcja wypisujaca informacje z tablicy Danych osobowych
void printarray(DaneOsobowe *array, int length)
{
	printf("\n\n");
	for (int i = 0; i < length; i++)
	{
		printf("id: %d imie: %s\n", array[i].id, array[i].imie);
	}

}