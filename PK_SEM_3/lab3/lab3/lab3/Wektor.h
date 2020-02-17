#pragma once
#include "punkt.h"

class Wektor :public Punkt
{
	double dlugosc;
	double kierunek;

public:
	Wektor(const Punkt & p = { 0,0 }); //konstruktor dla punktu i dla dwoch warotsci np Wektor W1({1,1});
	Wektor(const Wektor &w);
	Wektor(const Wektor * w);
	Wektor(const double & x_,const double & y_, const double &dl=0, const double &kierunek=0);
	
	void drukuj();

	double get_dlugosc(double,double);
	double get_kierunek(double,double);
	void operator=(const  Wektor &);
	bool operator==(const Wektor &);
	Wektor operator+(const Wektor &);
	bool operator>(const Wektor & );
	bool operator<(const Wektor & );

	friend class TablicaWektorow;
	friend class TabWektorSort;
	//friend void TablicaWektorow::print();
	
};

