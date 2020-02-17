#include "functions.h"
#include <stdio.h>

int load(char string[],int length)
{
	int i;
	for (i = 0; i <= length; i++) // ilosc iteracji jest o 1 wieksza od dlugosci nr pesel zeby moc sprawdzic czy ostatnim znakiem jest enter(sygnal konca)
	{
		scanf("%c", &string[i]); //pobieranie znaku do tablicy 
		if (i != length && string[i] == '\n')
			return 0; //nr pesel jest za krotki 
	}

	if (string[length] != '\n') 
		return 1;		//dlugosc podanego ciagu znakow jest za dluga

	string[length] = 0; //wstawienie na ostatnim do ostatniego elementu tablicy znaku sygnalizujacego koniec ciagu char'ow
	
	return 2; //prawdilowa dlugosc
}

int validate(char pesel[])
{
	int multiplier[11]={1, 3, 7, 9, 1, 3, 7, 9, 1, 3,0}; //Wagi poszczegolnych cyfr numeru pesel, wykorzystywane 
														 // do obliczenia sumy kontrolnej.										
	int checksum = 0; //Suma kontrolna
	 
	int i;
	for ( i = 0; i < 11; i++)	//petla odpowiedzialna za przechodzenie po pojedynczych elementach tablicy
	{
		if (pesel[i]<'0' || pesel[i]>'9')
			return 0; //Aktualnie sprawdzany znak jest bledny.

		checksum += (  multiplier[i] * (pesel[i] - '0')  ) %  10;    //Obliczanie wartosci do dodania do sumy kontrolnej.
																     // Dzieki reszcie z dzielenia  brana pod uwage jest tylko 
																	// liczba jednosci			
	}
	checksum = 10 - (checksum % 10); //oblicznanie ostatecznej wartosci sumy kontrolnej
	

	if (pesel[10]-'0' != checksum)		//sprawdzenie czy ostatnia cyfra nr pesel jest poprawna
		return 0; //Numer pesel jest bledny.
	else
		return 1; //Numer pesel jest poprawny.
}

void printinfo(char pesel[])
{
	if (pesel[9] % 2)
		printf("\nPlec: Mezczyzna"); 
	else
		printf("\nPlec: Kobieta");

	//RRMMDD
	//012345

	if (pesel[2] > '1')		//Sprawdzenie tysiaclecia
		printf("\nData urodzenia %c%c-%c%c-20%c%c", pesel[4], pesel[5], pesel[2]-2, pesel[3], pesel[0], pesel[1]); 
	
	else										
		printf("\nData urodzenia %c%c-%c%c-19%c%c", pesel[4], pesel[5], pesel[2], pesel[3], pesel[0], pesel[1]);

}

void clear()
{
	while (getchar() != '\n'); //pobieranie znaku do momentu natrafienia na enter
}