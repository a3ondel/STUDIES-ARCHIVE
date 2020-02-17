#include <iostream>
#include "punkt.h"
#include "Wektor.h"
#include "TablicaWektorow.h"
#include "TabWektorSort.h"


int main()
{
	Punkt A1;
	Punkt B1(1, 5);
	Punkt C1(A1);

	
	//double x_[10] = { 1,2,3,4,5,6 };
	//double y_[10] = { 6,3,4,5,1};
	Wektor W0(A1);
	Wektor W1({ 0,10 });
	Wektor W2({ 0,-10 });
	Wektor W3({ 1,1 });
	Wektor W4({ 0,0 }); // test inicjalizacji obiektu roznymi wartosciami
	Wektor W6({ 100,0 }); // test inicjalizacji obiektu roznymi wartosciami

	Wektor W5(W1); // konstruktor kopiujacy 
	//-------------------------------------------------konstruktory dla wektorow
	W5 = W0 + W1; // dodawanie i przypisanie 
	
	TablicaWektorow T1;
	TablicaWektorow T2(10,W5);
	TablicaWektorow T3(T2);   //konstrutory przetestowane


	TabWektorSort Ts1(T2);
	TabWektorSort Ts2(T2);

	//Ts1.print();
	Ts2.print();
	
	Ts1.wstaw(W1);
	Ts1.wstaw(W2);
	Ts1.wstaw(W3);
	Ts1.wstaw(W4); //Testowane przez nasa
	Ts1 = W3;
	Ts2.wstaw(W4);
	Ts2.wstaw(W3);
	Ts2.wstaw(W2);
	Ts2.wstaw(W1);
	Ts2.wstaw(W6);
	std::cout << "asdsdasdasda" << std::endl;
	Ts2.print();
	return 0;

}