/** @file */

/*

PLIK Z FUNKCJAMI PROGRAMU


*/
#include "FUNCKJE.h"

using namespace std;

bool pob_param(Parametry &parametry,  int ile, char * params[])
{
	double suma = 0;//suma kontrolna

	if (ile % 2 == 0||ile<13) //spr czy wszystkie param
		return true;
	
	for (int i = 1; i < ile; i += 2)
	{
		std::string tmp = params[i];
		if (tmp == "-k")
		{
			if (czy_calkowita(params[i + 1])) 
					return true;
			suma += 0.01;
			parametry.k = atoi(params[i + 1]);
		}
		else {

			if (tmp == "-p")
			{
				if (czy_calkowita(params[i + 1]))
					return true;
				suma += 0.1;
				parametry.p = atoi(params[i + 1]);
			}
			else {

				if (tmp == "-w")
				{
					if (czy_zmienno(params[i + 1])|| strtod(params[i + 1], nullptr) > 1)
						return true;
					suma += 1;
						
						parametry.w = strtod(params[i + 1], nullptr);
						
				}
				else {

					if (tmp == "-r")
					{
						
						if (czy_zmienno(params[i + 1])|| strtod(params[i + 1], nullptr) > 1)
							return true;
						suma += 10;
						parametry.r = strtod(params[i + 1], nullptr);
						
					}
					else {

						if (tmp == "-i")
						{
							if (czy_plik(params[i + 1]))
								return true;
							suma += 100;
							parametry.plikin = params[i + 1];
						}
						else {

							if (tmp == "-o")
							{
								suma += 1000;
								if (czy_plik(params[i + 1])) 
									return true; 
								parametry.plikout = params[i + 1];
							}
							else { 
								
								return true; //blad
							}
						}
					}
				}
			}
		}
	}
	
	if (suma == 1111.11 && (parametry.w < parametry.r)) 
		return false;
	
		return true; //jezeli blad
 }

bool czy_puste(const string tekst)
{
	string znaki = " ";
	if (tekst == "") return 1;

	return (tekst.find_first_not_of(znaki) == string::npos);
}

bool czy_calkowita(const char* Tekst)
{
	string znaki = "0123456789";
	string tekst = Tekst;

	return (tekst.find_first_not_of(znaki) != string::npos);
}


bool czy_calkowita(const string tekst)
{
	string znaki = "0123456789 ";  //spacja jest wymagana(czytanie z linii)

	return ((tekst.find_first_not_of(znaki) != string::npos));
}


bool czy_zmienno(const char* Tekst) //rzeczywiste nieujemne
{
	string znaki = "0123456789.";
	string tekst = Tekst;

	return (tekst.find_first_not_of(znaki) != string::npos);
}


bool czy_plik(const char* Tekst)
{
	string znaki = "\\/*?:|";//znaki niedozowolone przez system windows
	string tekst = Tekst;

	return (tekst.find_first_of(znaki) != string::npos);
}


 int pob_pop(Populacja &populacja, std::string nazwa_pliku)
{
	Osobniki *osobniki = nullptr; //glowa populacji 
	
	string a = nazwa_pliku;
	ifstream plik(nazwa_pliku);
	if (plik)
	{

		int ilosc_osobnikow = 0;
		int  dlugosc_genow = 0;
		string liniatmp = "";

		int b = 0;
		while (getline(plik, liniatmp))
		{
			if (czy_puste(liniatmp)) continue;
			istringstream linia(liniatmp);
			
			dlugosc_genow = 0;
			Geny *chromosomy(nullptr);

			
			while (linia >> b)
			{
				
				dodaj_nakon(chromosomy, b);
				dlugosc_genow++;
			}

			if (czy_calkowita(liniatmp) || dlugosc_genow < 2)
			{
				usun(chromosomy);
				usun(osobniki);
				populacja = { 0,nullptr };
				
				return 1; // nieprawidlowe dane
				
			}
			else
			{
				dodaj_nakon(osobniki, chromosomy, dlugosc_genow);
				ilosc_osobnikow++;
			}
		}

		plik.close();
		populacja = { ilosc_osobnikow,osobniki };
		return 0; // poprawne dane
	}
	
	return 2; // Blad przy otwierania pliku
}


 void dodaj_nakon(Geny *&phead, const int &chromosom)
 {
	 
	 if (phead)
	 {
		 Geny *pheadtmp = phead;

		 while (phead->Gnext)
		 {
			 phead = phead->Gnext;
		 }
		 phead->Gnext = new Geny{ chromosom,nullptr };
		 phead = pheadtmp;
	 }
	 else
		 phead = new Geny{ chromosom,nullptr };
 }


 void dodaj_nakon(Osobniki *&osobniki, Geny *chromosomy, int dlugosc_genomu)
 {
	 if (osobniki)
	 {
		 Osobniki *listatmp = osobniki;
		 while (osobniki->Onext)
		 {
			 osobniki = osobniki->Onext;
		 }

		 osobniki->Onext = new Osobniki{ dlugosc_genomu,  f(chromosomy),  chromosomy,  nullptr };
		 osobniki = listatmp;
	 }
	 else
		 osobniki = new Osobniki{ dlugosc_genomu,  f(chromosomy),  chromosomy,  nullptr };
 }


 bool cykl(Populacja &populacja,const double &k,const double &p, const double &w, const double &r)
 {
	 
	 srand(time(NULL));

	 dwa_wsk para_osobnikow;

	 if (populacja.Ldlugosc < 2)
		 return true;  

	 for (int i = 0; i < p; i++)
	 {
		 if (populacja.Ldlugosc > 1)
		 {
			 for (int j = 0; j < k; j++)
			 {
				 para_osobnikow = przesuwanie(populacja, losowanie_par(populacja.Ldlugosc));

				 krzyzowanie(para_osobnikow.Oa, para_osobnikow.Ob);
			 }

			 spr_przystosowania(populacja, w, r);
		 }
		 else
			 return false; 
	 }

	 return false;
 }


void krzyzowanie( Osobniki *&osobnikA, Osobniki *&osobnikB)
{
	
	Geny*Atmp = osobnikA->Gglowa, *Btmp = osobnikB->Gglowa, *Zamiana;
	
	//---------------------------losowanie miejsca pekniecia-------------------------
		int dlugoscA_pekniete = rand() % (osobnikA->Odlugosc -1); //Dlugosc zawsze wieksza od 1
	
	for (int i =0; i <dlugoscA_pekniete; i++)
	{
		Atmp = Atmp->Gnext; //przechodznie po liscie
	}
		int dlugoscB_pekniete = rand() % (osobnikB->Odlugosc-1);

	for (int i = 0; i < dlugoscB_pekniete; i++)
	{
		Btmp = Btmp->Gnext;
	}

	//---------------------------obliczanie dlugosci genomu
	int dlugosctmp = osobnikA->Odlugosc;
	
	osobnikA->Odlugosc = dlugoscA_pekniete+osobnikB->Odlugosc-dlugoscB_pekniete; 
	osobnikB->Odlugosc = dlugoscB_pekniete+dlugosctmp-dlugoscA_pekniete;

	//---------------------------przepinanie listy
	Zamiana = Atmp->Gnext;
	Atmp->Gnext = Btmp->Gnext;
	Btmp->Gnext = Zamiana;
	
	osobnikA->przystosowanie = f(osobnikA->Gglowa);
	osobnikB->przystosowanie = f(osobnikB->Gglowa);
}


double f(const Geny * osobnik)
{
	
	int max = 0, dlugosc = 0;
	double suma = 0;
	int tmp = 0;
	if (osobnik)
		max = osobnik->chromosom;
	

	while (osobnik)
	{
		dlugosc++;
		tmp = osobnik->chromosom;
		if (tmp > max) max = tmp;
		osobnik = osobnik->Gnext;
		suma += tmp;
	}
	if (max == 0) return 0;
	return suma / dlugosc / max;
}


void usun(Geny *&phead)
{
	while (phead)
	{
		Geny * ptmp = phead->Gnext;
		delete phead;
		phead = ptmp;
	}
}


void usun(Osobniki *&phead)
{
	while (phead)
	{
		Osobniki *ptmp = phead->Onext;
		usun(phead->Gglowa);
		delete phead;
		phead = ptmp;
	}
}


dwie_liczby losowanie_par(const int &zakres)
{
	int a, b;
	a = rand() % zakres;
	
	do
	{
	b = rand() % zakres;
	} while (a == b);

	// sortowanie 
	if (a < b)
		return { a,b };
	else
		return { b,a };
}


dwa_wsk przesuwanie(const Populacja &populacja,const dwie_liczby &a_b)
{
	Osobniki *osobnikAtmp=populacja.Oglowa, *osobnikBtmp;

	for (int  i = 0; i < a_b.a; i++)
	{
		osobnikAtmp = osobnikAtmp->Onext;
	}
	osobnikBtmp = osobnikAtmp;
	for (int i = 0; i < a_b.b-a_b.a; i++)
	{
		osobnikBtmp = osobnikBtmp->Onext;
	}
	
	return {osobnikAtmp,osobnikBtmp };
}


void spr_przystosowania(Populacja &populacja,const double &wymieranie,const double &rozmnazanie)
{

	Osobniki	*tmp = populacja.Oglowa, 
				*nastepny = tmp, 
				*poprzedni=nullptr;
	
		while(tmp)
		{
			nastepny = tmp->Onext;

			if (tmp->przystosowanie < wymieranie)
				usunosobnik(populacja,tmp,poprzedni);

			else 
			{
				if (tmp->przystosowanie > rozmnazanie)
					klonuj(populacja, tmp);

				poprzedni = tmp; // nie zostal usuniety wiec jest brany pod uwage
			}
			
			tmp = nastepny;
		}
}


void usunosobnik(Populacja &populacja, Osobniki *&slaby_osobnik, Osobniki *&poprzedni)
{
	if (slaby_osobnik)
	{
		
		if (populacja.Oglowa == slaby_osobnik)
			populacja.Oglowa = slaby_osobnik->Onext;
		else
			poprzedni->Onext = slaby_osobnik->Onext;

		populacja.Ldlugosc--;

		usun(slaby_osobnik->Gglowa);

		delete slaby_osobnik;
	}
}


void klonuj(Populacja &populacja,  Osobniki *&osobnik)
{
	Geny *wzor = osobnik->Gglowa;
	Geny *klon(nullptr);
	while (wzor)
	{
		dodaj_nakon(klon, wzor->chromosom);
		wzor = wzor->Gnext;
	}

	populacja.Oglowa = new Osobniki{ osobnik->Odlugosc,osobnik->przystosowanie,klon,populacja.Oglowa };
	populacja.Ldlugosc++;
}


bool zapisz(const Populacja &populacja, const string &nazwapliku)
{
	ofstream plik(nazwapliku);
	if (plik)
	{
		Osobniki *osobniki = populacja.Oglowa;


		while (osobniki)
		{
			Geny*geny = osobniki->Gglowa;
			{
				while (geny)
				{
					plik << geny->chromosom << ' ';

					geny = geny->Gnext;
				}
			}
			osobniki = osobniki->Onext;
			plik << endl;
		}
		plik.close();
		return false;
	}
	else
		return true;
}