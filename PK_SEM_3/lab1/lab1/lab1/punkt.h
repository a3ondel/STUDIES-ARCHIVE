#pragma once
class Punkt
{
	float x;
	float y;

	
public:
	Punkt(Punkt &p);
	Punkt(float x_ = 0, float y_ = 0);
	
	void dodaj(Punkt &p);//dodaje do siebie wsp�rz�dne punktu p (dodawanie wektor�w w przestrzeni 2d )
	void dodaj(Punkt *p);
	bool porownaj(Punkt &p); // funkcja wymagana do porownania dwoch punktow wewnatrz tablicy(private)

	void drukuj();// drukuje swoje wsp�rz�dne
	
	//friend class Tablica;
	
};