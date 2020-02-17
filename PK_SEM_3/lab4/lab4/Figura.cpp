#include "Figura.h"
#include "Szachownica.h"

bool Figura::set(int x_, int y_, char z)  		//pomocnicza uzywana przez range i set w sekcji public   ||UWAGA:(friend nie jest dziedziczony)
{
	
	s->wiz[x_][y_] = z;	

	return true;
};


bool Figura::set(int x_, int y_, Figura *f)		// ustawia pole x,y tablicy sz na wskaŸnik do klasy dziedzicz¹cej z klasy Figura (Wieza , Goniec)
{
	if (x_<0||x_>8||y_<0||y_>8||s->sz[x_][y_])
		return false;							//sprawdzanie czy pole nie jest zajete 
	s->sz[x_][y_] = f;	
	f->x = x_;
	f->y = y_;
	return true;
}

void Figura::remove()
{
	
	s->sz[x][y] = nullptr;
	s->wiz[x][y] = '.';
	s = nullptr;								// ustawia s na NULL - figura zdjêta z szachownicy 
}





