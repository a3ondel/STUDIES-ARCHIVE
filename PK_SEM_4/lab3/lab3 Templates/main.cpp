#include <iostream>
#include "classes.h"
#include "functions.h"

int main()
{
	std::cout << dodaj(1, 2) << std::endl;
	std::cout << dodaj('a','b') << std::endl;
	LINIA();
	Lista<int> x;
	x.dodaj(19);
	x.dodaj(20);
	x.dodaj(2);
	x.wypisz();
	

	Lista<Punkt> kartezjusz;
	kartezjusz.dodaj({ 10,2 });
	kartezjusz.dodaj({ 3,3 });
	kartezjusz.dodaj({ 9,9 });
	kartezjusz.wypisz();
	
	kartezjusz.delete_list();
	kartezjusz.wypisz();
	
	x.delete_list();
	x.wypisz();
	

	Schowek<std::string,int> smietnik("a", 1);
	smietnik.pokaz();


	return 0;
}