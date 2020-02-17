#include <iostream>
#include <string>
#include<iomanip>
#include <fstream>

using namespace std;



enum Oprawa
{
	TWARDA,MIEKKA
};
struct book
{
	string nazwa;
	Oprawa okladka;
	int nr;
};

string enumto_s(Oprawa okladka);
bool wstaw(const  book &ksiazka, book biblioteka[], const int N, int &licznik);
bool zapis(string plik_nazwa,const book biblioteka[],const int licznik );
bool odczyt(string plik_nazwa, const book biblioteka[], const int licznik);
int main()
{
	/*
	//blad wczytywania
	int a = 0, b = 0;

	cin >> a;
	if (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
	cin >> b;
	if (!cin) cout << "o";
	cout << a << "\n" << b;*/

	int licznik = 1;
	const int N = 2;
	book biblioteka[N]{ {"janusz",TWARDA,223} };
	const book wiedzmin{ "wiedzmin",MIEKKA,456 };
	


	
	
	
	
	string a = "";
	if(!wstaw(wiedzmin, biblioteka, N, licznik)) cout<<"nie ma miejsca" ;
	/*for (int  i = 0; i < N; i++)
	{
		
		cout << setw(10) << biblioteka[i].nazwa << setw(10) << "okladka:  " << enumto_s(biblioteka[i].okladka)<<setw(10) << biblioteka[i].nr<<endl;
	}
*/
	odczyt("test", biblioteka, licznik);

	return 0;
}
bool wstaw(const  book &ksiazka,book biblioteka[], const int N, int &licznik)
{
	
	if (licznik == N) 
		return 0;
	licznik++;
	biblioteka[licznik-1] = ksiazka;

	

	return 1;
}
bool zapis(string plik_nazwa, const book biblioteka[], const int licznik)
{
	ofstream plik(plik_nazwa);
	if (plik)
	{

		for (int i = 0; i < licznik; i++)
		{
			plik << biblioteka[i].nr << " "<<biblioteka[i].okladka << " "<< biblioteka[i].nazwa << endl;
		}
		plik.close();
	}
	else
		return 1;
	return 0;
}
bool odczyt(string plik_nazwa, const book biblioteka[], const int licznik)
{
	ifstream plik(plik_nazwa);
	string nazwa = "";
	int nr = 0;
	int okladka = 0;
	int i = 0;
	if (plik)
	{

		while (i<licznik)
		{
			plik >> nr >> okladka;
			getline(plik, nazwa);
			cout << nr << " " << okladka << " " <<nazwa << endl;
			i++;
		}
		plik.close();
	}
	else
		return 1;
	return 0;
}
string enumto_s(Oprawa okladka)
{
	if (okladka) return "TWARDA";
	return "MIEKKA";
}