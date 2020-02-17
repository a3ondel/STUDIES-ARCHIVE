#include <iostream>
#include <string>
#include <fstream>
enum Kierunek {POZIOMO,PIONOWO};
enum Typ { PUSTE=0,CZARNE=-1,LITERA=1};
const unsigned int W = 5, S = 5;
using namespace std;
struct Pole
{
	Typ typ;
	char litera;
};

bool sprawdz(Pole krzyzowka[W][S], unsigned int y, unsigned int x, const string &haslo, Kierunek kierunek)
{
	
	if (kierunek)
	{
		if (haslo.length() > W|| haslo.length()+y>W)
			return 1;

	}
	else
	{
		if (haslo.length() > S||haslo.length()+x>S) return 1;

	}

	for (int i=0;i<haslo.length();i++)
	{
		if (kierunek)
		{
			if (krzyzowka[y+i][x].typ == -1) return 1;
			if (krzyzowka[y+i][x].litera >= 'a')
			if (haslo[i] != krzyzowka[y+i][x].litera) return 1;


		}
		else 
		{
			if (krzyzowka[y][x+i].typ == -1) return 1;
			if(krzyzowka[y][x + i].litera>='a')
			if (haslo[i] != krzyzowka[y][x+i].litera) return 1;


		}
	}
	
	if (kierunek)
	{
		
		if (haslo.length() +y< W)if(krzyzowka[y + haslo.length()][x].typ ==PUSTE)
			return 1;
		
	}
	else
	{
		
		if (haslo.length() + x < S)if (krzyzowka[y][x + haslo.length() ].typ != CZARNE)
		{
			cout << "chuj";
			return 1;
		}
			
	}
	
	return 0;
}
bool wstaw(Pole krzyzowka[W][S], unsigned int y, unsigned int x,  const string &haslo, Kierunek kierunek)
{
	if (sprawdz(krzyzowka,y,x,haslo,kierunek)) 
		return 0;
	
	for (int i = 0; i < haslo.length(); i++)
	{
		if (kierunek)
		{
			krzyzowka[y + i][x] ={LITERA, haslo[i]};
			
		}

		else
		{
			krzyzowka[y][x + i] = {LITERA ,haslo[i]};
			
		}
	}
	return 1;
}


bool czytaj(Pole krzyzowka[W][S],  const string &nazwa )
{
	
	ifstream plik(nazwa);
	if (plik)
	{
		string haslo = "";
		int x = 0;
		int y = 0;
		string krek ="";
		Kierunek kierunek;
		while (!plik.eof())
		{
			
			plik >> haslo>>x>>y;
			if (haslo == "") break;
			//plik >> x;
			//plik >> y;
			//plik >> krek;
			getline(plik,krek);
			
			if (stoi(krek))
				kierunek = PIONOWO;
			else
				kierunek = POZIOMO;

			if (!wstaw(krzyzowka, y, x, haslo, kierunek)) cout << "xd";
				

			

		}
		
		

	}
	else cout << "nie udalo sie otworzyc pliku";
	return 0;
}

int main()
{
	Pole tab[W][S]{ PUSTE,0 };
	//tab[4][1]={ CZARNE, 0 };
	tab[3][3] = { CZARNE, 0 };
	tab[3][2] = { CZARNE, 0 };
	tab[3][1] = { CZARNE, 0 };
	tab[1][2] = { CZARNE,0 };
	tab[1][3] = { CZARNE,0 };
	tab[1][1] = { CZARNE,0 };
	//tab[1][3] = { CZARNE,0 };
	//tab[2][4] = { CZARNE,0 };

	
	if (czytaj(tab, "ser.txt")) cout << "wystapil blad" << endl;
	cout << endl;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < S; j++)
		{
			switch (tab[i][j].typ)
			{
			case CZARNE: cout << "#";
				break;
			case PUSTE: cout << "_"; 
				break;
			default:	cout << tab[i][j].litera;
				break;
			}
			
		}
		cout << endl;
	}
	cout << endl << endl << tab[4][4].typ; \
		int a;
	cin>>a;
	return 0;

	
}