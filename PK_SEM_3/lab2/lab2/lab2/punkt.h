#pragma once
#include <iostream>
class Punkt
{
	float x;
	float y;

	
public:
	Punkt(const Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	
	void dodaj(Punkt &p);//dodaje do siebie wspó³rzêdne punktu p (dodawanie wektorów w przestrzeni 2d )
	void dodaj(Punkt *p);
	bool porownaj(Punkt &p); // funkcja wymagana do porownania dwoch punktow wewnatrz tablicy(private)

	void drukuj();// drukuje swoje wspó³rzêdne
	
	friend class Tablica;

	//--------------------------------------------------------------------lab2
	void operator+=(const Punkt & p);
	void operator=(const Punkt & p);
	bool operator==(const Punkt & p);
	Punkt operator+(const Punkt & p);
	friend std::ostream &operator<<(std::ostream &output, const Punkt &p);
};
