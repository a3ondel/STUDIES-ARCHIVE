#pragma once

//#include "Szachownica.h"
class Szachownica;

class Figura
{
protected:
	Szachownica *s; 						//figura zna swoj¹ szachownice - ustawiane przez set
	int x, y;			 					// po³o¿enie na szachownicy ustawiane przez set 

	bool set(int x_, int y_, char z);			//pomocnicza uzywana przez range i set w sekcji public   ||UWAGA:(friend nie jest dziedziczony)
	bool set(int x_, int y_, Figura *f);		// ustawia pole x,y tablicy sz na wskaŸnik do klasy dziedzicz¹cej z klasy Figura (Wieza , Goniec)

public:
	Figura() { s = nullptr; x = 0; y = 0; };

	virtual bool set(Szachownica *s, int x_, int y_) = 0;
							//metoda ustawia figure na szachownicy
							// zwraca false gdy pole jest zajête
							// w tablicy wiz ustawia 'W' lub 'G' (dalsza czêœæ zadania)
							// za pomoc¹ set(int x,int y,Figura *f) ustawia pole w tablicy sz.

	void remove();
	virtual void range() = 0;
	
};

