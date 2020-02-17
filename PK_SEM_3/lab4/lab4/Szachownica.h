#pragma once

#include "Figura.h"

class Szachownica
{
	Figura *sz[8][8];						// tablica kontrolna zawieraj�ca wska�niki do ustawionych figur // NULL w przypadku gdy pole jest puste;
	char wiz[8][8];
											// tablica do wizualizacji : 'o' pole puste 'X' pole bite , 'G'- polo�enie go�ca,
											// 'W' - po�o�enie wie�y; zapisywane przez metod� range klasy Figura
public:
	
	Szachownica();						// tworzy pust� szachownic�: pola w tablicy sz ustawione na NULL , w tablicy wiz na 'O' 

	void showRange(); 						// metoda wywo�uje na wszystkich polach tablicy sz (r�nych od NULL) //metod� wirtualn� range 
	void display(); 						// wy�wietla szachownnice (tablica wiz)
	void clear();
	friend class Figura;
	friend class Wieza;
	friend class Goniec;
	~Szachownica()=default;
};

