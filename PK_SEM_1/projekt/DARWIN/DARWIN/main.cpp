/** @file */

/*

MAIN 


*/
#include "FUNCKJE.h"
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>  

using namespace std;

void onExit(void)
{
	_CrtDumpMemoryLeaks();
}


int main(int ile, char * params[])
{
	atexit(onExit); // wycieki pamieci
	Populacja populacja{ 0,nullptr }; 
	Parametry parametry;

	if (pob_param(parametry, ile, params))
	{
		cout << "Bledne parametry";
		return 1;
	}
	
	
	switch (pob_pop(populacja, parametry.plikin))
	{
	case 1: cout << "Nieprawdilowe dane";
		break;

	case 2: cout << "Blad pliku odczytu";
		break;

	default: if (cykl(populacja, parametry.k, parametry.p, parametry.w, parametry.r))
		cout << "Za malo osobnikow w populacji";
			 else
		if (zapisz(populacja, parametry.plikout))
			cout << "Blad pliku zapisu"; 
		break;
	}

	usun(populacja.Oglowa);
	
	return 0;
}