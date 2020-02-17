//Zadanie c++ (PK3 lab 1)
//Dana jest klasa :
#include "punkt.h"



Punkt::Punkt(const Punkt &p) :x(p.x), y(p.y) {};

Punkt::Punkt(float x_, float y_) : x(x_), y(y_) {};

void Punkt::dodaj(Punkt &p)
{

	this->x += p.x;
	this->y += p.y;

}
void Punkt::dodaj(Punkt *p)
{

	this->x += p->x;
	this->y += p->y;

}

void Punkt::drukuj()
{
	std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}

bool Punkt::porownaj(Punkt & p)
{
	if (this->x == p.x&&this->y == p.y)
		return true;
	else
		return false;
}

//----------------------------------------lab2
void Punkt::operator+=(const Punkt & p)
{
	this->x += p.x;
	this->y += p.y;

}

void Punkt::operator=(const Punkt & p)
{
	this->x = p.x;
	this->y = p.y;

}

bool Punkt::operator==(const Punkt & p)
{
	if (this->x == p.x && this->y == p.y)
		return true;
	else
		false;
}

Punkt Punkt::operator+(const Punkt & p)
{
	return { this->x + p.x,this->y + p.y };
}

std::ostream &operator<<(std::ostream &output, const Punkt &p)
{
	output << "x: " << p.x << " y: " << p.y << std::endl;
	return output;
}


