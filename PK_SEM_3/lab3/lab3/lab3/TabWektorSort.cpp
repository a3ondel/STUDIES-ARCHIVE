#include "TabWektorSort.h"

int compareMyType(const void * a, const void * b)
{
	
	if (*(Wektor*)a < *(Wektor*)b) return -1;
	if (*(Wektor*)a == *(Wektor*)b) return 0;
	if (*(Wektor*)a > *(Wektor*)b) return 1;
	

}


TabWektorSort::TabWektorSort(const TablicaWektorow &t1) :TablicaWektorow(t1) { this->sort(); }


TabWektorSort::~TabWektorSort()
{
	if(this->w)
		delete[] this->w;
	this->w = nullptr;
}

void TabWektorSort::sort()
{
	qsort(this->w, dl, sizeof(Wektor), compareMyType);
}

void TabWektorSort::wstaw(const Wektor & v1)
{
	Wektor * nowy = new Wektor[this->dl + 1];
	int a = 0;
	for (int i = 0; i < dl; i++)
	{
		if (w[i] > v1&&!a)
		{
			a = 1;
			nowy[i] = v1;

		}
		nowy[i + a] = w[i];
	}
	if (!a)
		nowy[dl] = v1;
	delete[] w;
	w = nowy;
	dl++;
	
}

void TabWektorSort::print()
{
	for (int i = 0; i < dl; i++)
	{
		this->w[i].drukuj();
	}
}

void TabWektorSort::operator=(const Wektor & w1)
{
	this->wstaw(w1);
}
