#include "Wektor.h"
#include <cmath>
constexpr double PI = 3.14159265359;

Wektor::Wektor(const Punkt & p1):Punkt(p1) 
{
	this->dlugosc = this->get_dlugosc(p1.x,p1.y);
	this->kierunek = this->get_kierunek(p1.x, p1.y);
}

Wektor::Wektor(const Wektor & w) :Punkt(w.x, w.y), kierunek(w.kierunek), dlugosc(w.dlugosc) {};

Wektor::Wektor(const Wektor * w) :Punkt(w->x, w->y), kierunek(w->kierunek), dlugosc(w->dlugosc) {};

Wektor::Wektor(const double & x_, const double & y_, const double & dl, const double & kierunek):Punkt(x_,y_)
{
	this->dlugosc = this->get_dlugosc(x_,y_);
	this->kierunek = this->get_kierunek(x_, y_);
}

void Wektor::drukuj()
{
	std::cout << "dlugosc: " << this->dlugosc << " kierunek: " << this->kierunek << " x: " << this->x << " y: " << this->y << std::endl;
}

double Wektor::get_dlugosc(double x_,double y_)
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

double Wektor::get_kierunek(double x_,double y_)
{
	if (this->x)
		return atan(this->y / this->x);
	else if (this->y == 0)
		return 0;
	else if (this->y > 0)
		return PI / 2;
	else
		return  3 * PI / 2;
}

void Wektor::operator=(const Wektor & w)
{
	this->x = w.x;
	this->y = w.y;
	this->dlugosc = w.dlugosc;
	this->kierunek = w.kierunek;
}

bool Wektor::operator==(const Wektor & w)
{
	if (this->kierunek == w.kierunek&&this->dlugosc == w.dlugosc)
		return true;
	else
		return false;
}



Wektor Wektor::operator+(const Wektor & w)
{
	return { this->x + w.x,this->y + w.y };
}

bool Wektor::operator>(const Wektor & w)
{
	if (this->dlugosc > w.dlugosc)
		return true;
	else
		return false;
}

bool Wektor::operator<(const Wektor & w)
{

	if (this->dlugosc < w.dlugosc)

		return true;
	else
		return false;
}
