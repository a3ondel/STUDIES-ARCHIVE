/*
Programowanie Komputerów 2
Laboratorium nr. 1
Zadanie: Napisaæ program sprawdzaj¹cy numer pesel i wypisuj¹cy informacje w nim zawarte.
Autor: Adam Trznadel
Informatyka sem.2, gr.2, sekcja 2 czwartek: 10.15-11.45
Data wys³ania zadania: 04.03.2019
*/

#include "functions.h"
#include <stdio.h>
int main()
{
	char PESEL[12]; //tablica 
	char key;
	do
	{
		printf("Podaj nr pesel: ");
			
		switch (load(PESEL,11)) //pobieranie znakow do tablicy i wypisywanie stososnych komunikatow
			{
			case 0 :  
					 printf("\nPodany nr pesel jest za krotki");
				break;
			case 1 :  
					  printf("\nPodany nr pesel jest za dlugi");
					  clear(); //czyszczenie bufora
			    break;
			case 2 : 
					if (validate(PESEL)) //sprawdzanie numeru pesel
					{
						printf("\nPodany nr pesel jest poprawny");
						printinfo(PESEL); //wypisywanie informacji z numeru pesel tj. plec, data urodzenia
					}
					else
						printf("\nPodany nr pesel jest niepoprawny");
			}		
		
		printf("\n\nNacisnij k aby zakonczyc lub dowolnie inny klawisz aby kontynuowac\n\n");
		key = getch(); //pobieranie znaku 
		
	} while (key != 'k');
	
	return 0;
}