#pragma once

#include "Figura.h"

class Szachownica
{
	Figura *sz[8][8];						// tablica kontrolna zawieraj¹ca wska¿niki do ustawionych figur // NULL w przypadku gdy pole jest puste;
	char wiz[8][8];
											// tablica do wizualizacji : 'o' pole puste 'X' pole bite , 'G'- polo¿enie goñca,
											// 'W' - po³o¿enie wie¿y; zapisywane przez metodê range klasy Figura
public:
	
	Szachownica();						// tworzy pust¹ szachownicê: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 

	void showRange(); 						// metoda wywo³uje na wszystkich polach tablicy sz (ró¿nych od NULL) //metodê wirtualn¹ range 
	void display(); 						// wyœwietla szachownnice (tablica wiz)
	void clear();
	friend class Figura;
	friend class Wieza;
	friend class Goniec;
	~Szachownica()=default;
};

