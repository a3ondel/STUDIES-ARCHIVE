/** @file */


/*

PLIK NAGLOWKOWY FUNCKJI 


*/
#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "STRUKTURY.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>

using namespace std;


/**
	Funkcja pobiera parametry i je weryfikuje.


@param ile ilosc elementow w tablicy parametrow
@param *params[] tablica z parametrami
@param parametry wsystkie parametry 
@return kody bledow, tj. 0-brak bledow, 1-zle parametry paramtrow

*/
bool pob_param(Parametry &parametry, int ile, char *params[]);


/**
	Funkcja sprawdza czy tekst sklada sie ze spacji lub jest pusta linia.
	
	
@param tekst ktory bedzie sprawdzany
@return zwraca 1- jezeli string tekst jest pusty lub sklada sie ze spacji, 0-jezeli nie spelnia warunkow
*/
bool czy_puste(const string tekst);


/**
	Funkcja sprawdza czy ciag znakow spelnia warunki liczby calkowitej.


@param Tekst badany ciag znakow
@return kody bledow, tj. 0-ciag spelnia warunki 1-ciag nie spe³nia warunkow

*/
bool czy_calkowita(const char *Tekst);

/**
	Funkcja sprawdza czy teskst spelnia warunki liczby calkowitej, zezwalajac przy tym na spacje.


@param tekst badany string
@return kody bledow, tj. 0-ciag spelnia warunki 1-ciag nie spe³nia warunkow

*/
bool czy_calkowita(const string tekst);


/**
	Funkcja sprawdza czy Teskst spelnia warunki liczby zmienno-przecinkowej.


@param Tekst badany ciag znakow
@return kody bledow, tj. 0-ciag spelnia warunki 1-ciag nie spe³nia warunkow

*/
bool czy_zmienno(const char *Tekst);

/**
	Funkcja sprawdza czy Teskst spelnia warunki dotyczace nazwy pliku.


@param Tekst badany ciag znakow 
@return kody bledow, tj. 0-ciag spelnia warunki 1-ciag nie spe³nia warunkow

*/
bool czy_plik(const char *Tekst);

/**
	Funkcja pobiera populacje z podanego pliku.
	W trakcie pobierania weryfikuje poprawonsc danych.
	Jezeli funckja zakonczy sie przez blad danych, wartosci zmienej populacja wyzeruja sie.
	Gdy funckja zakonczy dzialanie pomyslnie, zmienna populacja otrzyma poprzez 
	referencjce zaktualizowane dane.


@param populacja  
@param nazwa_pliku 
@return zwraca kody bledow, tj. 0-pobieranie zakonczone pomyslnie, 1-nieprawidlowe dane, 2-blad przy otwieraniu pliku.

*/
int pob_pop(Populacja &populacja, std::string nazwa_pliku);

/**
	Funkcja przeprowadzajaca rozne modifkacje na populacji, tj. krzyzowanie, 
	usuwanie osobnikow i klonowanie poprzez funckje sprawdzanie przystowowania.
	

@param populacja populacja na ktorej beda wykonwyane modyfikacje
@param k ilosc par do losowania
@param p ilosc pokolen
@param w prog wymierania
@param r prog rozmnazania
@return zwraca kody bledow, tj. 0-cykl zakonczony pomyslnie, 1-za malo osobnikow.

*/
bool cykl(Populacja &populacja, const double &k, const double &p, const double &w, const double &r);

/**
	Funkcja miesza "chromosomy" z "genow"  OsobnikA i OsobnikaB.


@param osobnikA pierwszy osobnik na ktorym bedzie dokonywane krzyzowanie
@param osobnikB drugi osobnik do krzyzowania
*/
void krzyzowanie( Osobniki *&osobnikA,  Osobniki *&osobnikB);


/**
	Funkcja obliczajaca wartosc przystosowania podanego osobnika.


@param osobnik osobnik ktorego przystosowanie bedzie oceniane
@return zwraca wartosc przystosowania 

*/
double f(const Geny *osobnik);


/**
	Funkcja dodaje chromosomy na koniec listy z chromosami  osobnika.


@param phead wskaznik na poczatek listy z chromosomami
@param chromosom wartosc chromosomu 

*/
void dodaj_nakon(Geny *&phead, const int &chromosom);


/**
	Funkcja dodaje genom(liste chromosomow) osobnika na koniec listy osobnikow 
	i aktualizuje wartosc przystosowania.


@param osobniki wskaznik na osobnika
@param chromosomy wskaznik na pierwszy element listy z chromosomami (genom
@param dlugosc_genomu inaczej mowiac dlugosc listy na ktora wskazuje phead

*/
void dodaj_nakon(Osobniki *&osobniki, Geny *chromosomy, int dlugosc_genomu);


/**
	Funkcja usuwajaca liste z chromosomami (genom).


	@param phead wskaznik na pierwszy element listy

*/
void usun(Geny *&phead);


/**
	Funkcja usuwa liste z osobnikami.


@param phead wskaznik na pierwszy element listy osobnikow 

*/
void usun(Osobniki *&phead);


/**
	Funkcja usuwa pojedynczy element listy z osobnikami ze 
	zmiennej przechowujaca cala populacje.


@param populacja zmienna z ktorej bedzie usuwany osobnik
@param slaby_osobnik wskaznik na osobnika ktory bedzie usuwany
@param poprzedni wskaznik na poprzedniego osobnika listy z osobnikami 
jezeli nie istnieje to wynosi nullptr

*/
void usunosobnik(Populacja &populacja, Osobniki *&slaby_osobnik,Osobniki *&poprzedni);


/**
	Funkcja losuje dwie rozne liczby z podanego zakresu 
	(zakres musi byc wiekszy od 2)

	
@param zakres zakres losowanych liczb
@return zwraca strukture dwie_liczby.
Zwracane wartosci sa posortowane rosnaco


*/
dwie_liczby losowanie_par(const int &zakres);


/**
	Funkcja przemieszczajaca sie po populacji.


@param populacja populacja po ktorej bedziemy sie przemieszczac
@param a_b zmienna przechowujaca dwie liczby, ktore odpowiadaja
	za to o ile mijesc w liscie funckja ma sie przesuwac
@return zwraca strukture dwa_wsk przechowujaca dwa wskazniki na
element z listy osobnikow

*/
dwa_wsk przesuwanie(const Populacja &populacja,const dwie_liczby &a_b);


/**	
	Funkcja sprawdza czy osobnik powinien zostac usuniety, sklonowany,
	a nastepnie wykonuje odpowiednie operacje.


@param populacja populacja na ktorej operuje funkcja
@param wymieranie wartosc progu wymierania
@param rozmnazanie wartosc progu rozmnazania

*/
void spr_przystosowania(Populacja &populacja, const double &wymieranie,const double &rozmnazanie);


/**
	Funckja klonujaca i dodajaca osobnika na poczatek listy osobnikow.


@param populacja populacja w ktorej dojedzie do klonowania
@param osobnik osobnik ktory zostanie sklonowany
*/
void klonuj(Populacja &populacja,  Osobniki *&osobnik);


/**
	Funckja zapisujaca liste osobnikow do pliku


@param populacja populacja ktora bedzie zapisywana do pliku
@param nazwapliku string z nazwa pliku do zapisu
@return zwraca kody bledu 0-pomyslny zapis 1-blad pliku zapisu

*/
bool zapisz(const Populacja &populacja, const string &nazwapliku);


















#endif