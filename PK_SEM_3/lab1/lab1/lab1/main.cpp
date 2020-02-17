#include <iostream>
#include "punkt.h"
#include  "tablica.h"


int main()
{
	Punkt A1;
	Punkt B1(1, 5);
	Punkt C1(A1);
	Punkt *janusz = new Punkt(1, 1);
	Punkt *janusz2 = new Punkt;
	Punkt *janusz3 = new Punkt(*janusz2);
	
	C1.dodaj(B1);
	C1.dodaj(B1);
	A1.drukuj();
	B1.drukuj();
	C1.drukuj();

	janusz3->dodaj(janusz); //pointer-pointer
	janusz3->dodaj(janusz); 

	janusz2->dodaj(B1); //pointer-zwykly

	A1.dodaj(janusz3); //zwykly-pointer
	A1.drukuj();

	janusz->drukuj();
	
	float x_[10] = { 1,2,3,4,5,6 };
	float y_[10] = { 6,3,4,5 };

	Tablica t1(x_,y_, 4);
	Tablica t2(t1);

	bool aj = t1.porownaj(t2);
	t1.dodaj(t2);
	auto ajaja=t1.porownaj(t2);

	//dodatkowe funkcje drukujace
	std::cout << "/////" << std::endl;
	t1.drukuj();
	std::cout << "/////" << std::endl;
	t2.drukuj();
	//

	delete janusz; 
	delete janusz2;
	delete janusz3;

	return 0;



}