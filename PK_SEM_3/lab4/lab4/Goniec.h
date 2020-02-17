#pragma once
#include "Figura.h"
#include "Szachownica.h"
class Goniec :
	public Figura
{
public:
	Goniec() :Figura() {};
	void range() override;
	bool set(Szachownica *s_, int x_, int y_) override;

	friend class Szachownica;
	
};

