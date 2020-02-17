#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>

using namespace std;
struct Osobniki
{
	int gen;
	Osobniki *Onext;

};

struct Lista
{
	Osobniki *osobnik;
	Lista *Lnext;
};

void wypisz(Osobniki *phead)
{
	while (phead)
	{
		cout << phead->gen << ' ';
		
		phead = phead->Onext;
	}

}

void wypisz(Lista *phead)
{
	while (phead)
	{
		
		wypisz(phead->osobnik);

		phead = phead->Lnext;
		cout << endl;

	}

}
void dodaj_napocz(Lista *&lista, Osobniki *osobnik)
{
	lista = new Lista{ osobnik,lista };

}
void dodaj_nakon(Lista *&lista, Osobniki *osobnik)
{
	if (lista)
	{
		
		Lista *listatmp = lista;
		while (lista->Lnext)
		{
			lista = lista->Lnext;

		}
		lista->Lnext = new Lista{ osobnik,nullptr };
		lista = listatmp;
	}
	else 
		lista = new Lista{ osobnik,nullptr };
	
}
void dodaj_napocz(Osobniki *&phead, int gen)
{
	phead = new Osobniki{ gen,phead};
		
}

void dodaj_nakon(Osobniki *&phead, int gen)
{
	if (phead)
	{
		Osobniki *pheadtmp = phead;
		
		while (phead->Onext)
		{
			phead = phead->Onext;
		}
		phead->Onext = new Osobniki{ gen,nullptr };
		phead = pheadtmp;
	}
	else
		phead = new Osobniki{ gen,nullptr };
	
}
void usun(Osobniki *&phead)
{
	

	while (phead)
	{
		Osobniki * ptmp = phead->Onext;
		delete phead;
		phead = ptmp;
	}
}

void usun(Lista *&phead)
{


	while (phead)
	{
		usun(phead->osobnik);
		
		Lista *ptmp = phead->Lnext;
		delete phead;
		phead = ptmp;


	}

}

void krzyzowanie(Osobniki *A, Osobniki *B)
{
	srand(time(NULL));
	Osobniki *Atmp = A, *Btmp = B,*Zamiana;

	int dlugoscA = 0, dlugoscB = 0,dlugosctmp;
	/**
	
	A->gen = dlugosc genow osobnika 

	*/

	for ( dlugoscA = 0; dlugoscA < rand()%(A->gen-1)+1; dlugoscA++)
	{
		Atmp = Atmp->Onext;
		
	}
	for ( dlugoscB = 0; dlugoscB<rand()% (B->gen-1)+1; dlugoscB++)
	{
		Btmp = Btmp->Onext;
	}
	
	
	
	//da sie bez zmiennej pomocniczej wiecej obliczen
	dlugosctmp = A->gen;

	A->gen = dlugoscA + B->gen - dlugoscB;
	B->gen = dlugoscB + dlugosctmp - dlugoscA;

	
	
	Zamiana = Atmp->Onext;
	Atmp->Onext = Btmp->Onext;
	Btmp->Onext = Zamiana;


}

int main()
{
	Osobniki *A(nullptr);
	Osobniki *B(nullptr);

	Lista *C1(nullptr);
	Lista *C2(nullptr);
	
	
	dodaj_napocz(A, 4);
	dodaj_napocz(A, 3);
	dodaj_napocz(A, 2);
	dodaj_napocz(A, 1);
	dodaj_napocz(A, 4);
	
	
	dodaj_nakon(B, 5);
	dodaj_nakon(B, 6);
	dodaj_nakon(B, 7);
	dodaj_napocz(B, 3);
	
	//krzyzowanie(A, B);
	dodaj_nakon(C1, A);
	dodaj_napocz(C1, B);
	

	
	
	

	
	wypisz(C2);
	
	return 0;
}