#include "dynamic.h"
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

//wypelnianie tablicy Danymi
void dynamic_DO_load(DaneOsobowe *DOarray, int lenght)
{
	char buffer[256]; //tymczasowy bufor na string

	for (int i = 0; i < lenght; i++)
	{
		DOarray[i].id = i + 1; //numeracja zaczyna sie od 1, a iterator i od 0
		printf("\nPodaj imie:");
		DOarray[i].imie = dynamic_string_load(buffer); //wczytanie i ustawienie wskaznika na pierwszy element stringa
	}
}

//pobieranie imienia i zapisywanie do dynamicznej tablicy 
char* dynamic_string_load(char *buffer)
{
	do
	{
		fgets(buffer, 256, stdin); //pobieranie imienia (calej linii(dla imion ktore musza byc oddzielone przerwa))

	} while (strlen(buffer) < 2);//nie wczytywanie samych enterow

	if(buffer[strlen(buffer)-1]=='\n') //poprawa dlugosci stringa (fgets zawsze wczytuje znak nowej linii o ile uzytkownik nie wpisze ciagu o dlugosci 255)
	buffer[strlen(buffer) - 1] = '\0'; 
	
	char *tmp = (char*)malloc(sizeof(char)*(strlen(buffer)+1)); //rezerwowanie pamieci, + 1 zeby bylo miejsce na znak '\0'
	
	strcpy(tmp, buffer); //kopiowanie znakow z bufora do tmp
	
	return tmp; //zwrocenie wskaznika na pierwszy element 
}


//zwalnianie zaalokowanej pamieci
DaneOsobowe* freememory(DaneOsobowe *array,int length)
{
	for (int i = 0; i < length; i++)
	{
		free(array[i].imie); //zwalnianie pamieci ze znakiami imienia
		array[i].imie = NULL;//zerowanie wskaznika dla czytelnosci
	}

	free(array); //zwalnianie calej tablicy
	
	return NULL;
}

