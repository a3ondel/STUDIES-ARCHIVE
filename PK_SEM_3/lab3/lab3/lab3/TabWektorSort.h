#pragma once
#include "TablicaWektorow.h"
class TabWektorSort :
	public TablicaWektorow
{
public:
	
	TabWektorSort(const TablicaWektorow &t1 = {0,nullptr});
	~TabWektorSort();
	void sort();
	void wstaw(const Wektor & );
	void print();

	void operator=(const Wektor &);
};

int compareMyType(const void * a, const void * b);