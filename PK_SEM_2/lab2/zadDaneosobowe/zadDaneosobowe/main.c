/*
Autor: Adam Trznadel Gr. 2 AEI INF
Nr Lab: 2
Data wyslania: 24.03.2019
*/

#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "dynamic.h"
#include "comparing.h"
#include "print.h"

int main()
{
	int lenght; //dlugosc dynamicznej tablicy
	printf("Podaj ilosc danych osobowych: ");
	scanf("%d", &lenght);
	
	if (lenght > 0)
	{
		DaneOsobowe *DOarray = (DaneOsobowe*)malloc(sizeof(DaneOsobowe)*lenght); //inicjalizacja dynamicznej tablicy
		dynamic_DO_load(DOarray, lenght); //wypelnianie tablicy Doarray 


		qsort(DOarray, lenght, sizeof(DaneOsobowe), comparetorimie); //sortowanie tablicy DOarray wedlug imienia
		printarray(DOarray, lenght); //wypisywanie posortowanej tablicy


		qsort(DOarray, lenght, sizeof(DaneOsobowe), comparetorid); //sortowanie tablicy DOarray wedlug id
		printarray(DOarray, lenght); //wypisywanie posortowanej tablicy
		

		DOarray=freememory(DOarray, lenght); //zwalnianie zaalokowanej pamieci i ustawienie Doarray na null
	}
	else
	{
		printf("Podano niewlasciwa liczbe");
	}
	return 0;
}

