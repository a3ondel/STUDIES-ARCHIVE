/** @file */

/*

STRUKTURY PROGRAMU


*/
#ifndef STRUKTURY_H
#define STRUKTURY_H
#include <iostream>

/**
	Lista przechowujaca poszczegolne chormosomy (wartosci).
*/
struct Geny
{
	///wartosc chromosomu
	int	 chromosom;

	///wskaznik na kolejny element listy genow
	Geny *Gnext;
};


/**
	Lista przechowujaca informacje o poszczegolnych osobnikach.
*/
struct Osobniki
{	///dlugosc listy z chromosomami
	int Odlugosc;

	///wartosc funckji przystowsowania dla osobnika
	double przystosowanie;

	///wskaznik na poczatek listy z chromosomami
	Geny *Gglowa;

	///wskaznik na kolejny element listy osobnikow
	Osobniki *Onext;
};


/**
	Struktura przechowujaca liste osobnikow i jej dlugosc.
*/
struct Populacja
{
	///dlugosc listy z osobnikami
	int Ldlugosc;

	///wskaznik na pierwszy element listy Osobnikow
	Osobniki *Oglowa;
};


/**
	Struktura przechowujaca dwie liczby calkowite.

*/
struct dwie_liczby
{
	int a; 
	int b; 
};


/**
	Struktura przechowujaca dwa wskazniki na elementy listy osobnikow.

*/
struct dwa_wsk
{
	Osobniki *Oa;
	Osobniki *Ob;
};


/**
	Struktura przechowujaca parametry.

*/
struct Parametry
{
	///ilosc par do losowania
	int k;

	///ilosc pokolen
	int p;

	///prog wymierania
	double w;

	///prog rozmnazania
	double r;

	///nazwa pliku do odczytu
	std::string plikin;

	///nazwa pliku do zapisu
	std::string plikout;
};












#endif 
