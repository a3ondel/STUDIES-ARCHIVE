#include "print.h"
#include <stdio.h>
#include <Windows.h>
#include "utility.h"

void printmenu()
{

	cls();
	printf("Wybierz funkcje ekspresu poprzez wcisniecie klawisza:\n");
	printf("1.Przygotuj mala kawe\n");
	printf("2.Przygotuj duza kawe\n");
	printf("3.Przygotuj espresso\n");
	printf("4.Przygotuj cappucino\n");
	printf("5.Przygotuj gorace mleko\n");
	printf("6.Ustaw moc kawy\n");
	printf("7.Ustaw bazowa ilosc wody\n");
	printf("8.Wylacz ekspres\n");

}

//-----------------------------------------------------funkcje wypisujace informacje na temat "wykonywanych" czynnosci
void printmilk()
{
	cls();
	printf_s("Przygotowywanie mleka\n");
	Sleep(2000);
	printf_s("Mleko gotowe");
	Sleep(1000);
}

void printcapp()
{
	cls();
	printf_s("Przygotowywanie cappucino\n");
	Sleep(2000);
	printf_s("Cappucino gotowe");
	Sleep(1000);
}

void printespr()
{
	cls();
	printf_s("Przygotowywanie espresso\n");
	Sleep(2000);
	printf_s("Espresso gotowe");
	Sleep(1000);
}

void printbig()
{
	cls();
	printf_s("Przygotowywanie duzej kawy\n");
	Sleep(2000);
	printf_s("duza kawa gotowa");
	Sleep(1000);
}

void pintsmall()
{
	cls();
	printf_s("Przygotowywanie malej kawy\n");
	Sleep(2000);
	printf_s("mala kawa gotowa");
	Sleep(1000);
}