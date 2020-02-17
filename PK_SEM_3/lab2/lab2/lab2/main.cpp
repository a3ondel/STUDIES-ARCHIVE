#include <iostream>
#include "punkt.h"
#include  "tablica.h"


int main()
{
	Punkt A1;
	Punkt B1(1, 5);
	Punkt C1(A1);

	
	float x_[10] = { 1,2,3,4,5,6 };
	float y_[10] = { 6,3,4,5,1};
	Tablica t1(x_,y_, 10);
	Tablica t2(t1);
	Tablica t3(5);
	//-------------------------------lab2
	
	//---------------------punkty
	A1 += B1; //+= dziala
	A1 += B1;

	C1 = B1; // = dziala

	bool porownanie= C1 == B1;//  ==dziala
	bool porownanie2 = C1 == A1; 

	C1 = A1 + B1; //+ dziala

	std::cout << C1; //<< operator strumienia git

	//--------------------tablice

	t1 = t2; // przypisanie tablicy dziala
	bool tak =t1 == t2; //porownanie dziala
	bool nie = t1 == t3; 

	std::cout << t1; //wypisywanie tablicy

	t1[0] = { -1,-1 }; // odolywanie do elementow tablicy dziala
	std::cout <<std::endl<< t1[0];
	
	Tablica tplik("file.txt"); //konstruktor z wczytywaniem z pliku

	std::cout << tplik;

	return 0;

}