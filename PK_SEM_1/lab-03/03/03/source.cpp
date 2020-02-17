#include <iostream>
#include <Windows.h>
#include<iomanip>
using namespace std;

void piramida(int N);
void tr_L(int N);
void vx(int N);

void ciag(int a[],int N,int &poz,int &dl);
void wypisz_tab(int a[], int N,int poz,int dl);
void color(const int a);

int main()
{
	const int N = 30;
	int pozycja=0;
	int dlugosc=0;
	//piramida(11);
//	tr_L(10);
	//vx(10);
	int a[N] { 0,0,1,3,1,1,2,8,8,8,8,2,3,5,6,8,2,5,6,8, };//jezeli w wasatym 
	//nawiasie damy wartosci ale nie wszystkie to reszta pozycji otrzyma wartosc 0 np a[10] {} bedzie mialo 10 pozycji z wartoscia 0
	
	ciag(a, N,pozycja,dlugosc);
	wypisz_tab(a, N, pozycja, dlugosc);
	return 0;
}
void wypisz_tab(int a[], int N,int poz,int dl)
{
	color(15);
	cout << "\nDlugosc maksymalna: " << dl << "\nciag rozpoczyna sie na poz: " << poz << "\n\n";

	for (int i = 0; i < N; i++)
	{
		if (i >= poz&&i < poz + dl) color(10); else color(12);
		cout << setw(4) << a[i];
		
	}
	color(15);
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << i;
	}

}
void ciag(int a[],int N,int &poz, int &dl)
{
	int  dlugosc = 0, dlugosc_max = 0;
	
	for (int i = 1; i < N; i++)
	{
		if (a[i] == a[i - 1])
		{
			dlugosc++;
			if (dlugosc_max <= dlugosc)
			{
				dlugosc_max = dlugosc;
				poz = i - dlugosc+1;
				
			}
			
		}
		else
		{
			dlugosc = 1;
		}


	}
	dl = dlugosc_max;
	//cout << "\npozycja: " << poz << " dlugosc:" << dlugosc_max;
														

}


void piramida(int N)
{

	for (int w = 0; w < N; w++)
	{

		for (int k = 0; k < N - w; k++)
		{
			cout << "-";

		}
		for (int k = 1; k <= w * 2 + 1; k++)
		{
			cout << "X";
		}

		for (int k = 0; k < N - w; k++)
		{
			cout << "-";
		}
		cout << endl;

	}
}

void tr_L(int N)
{
	for (int w = 1; w <= N; w++)
	{
		for (int k = 1; k <= w; k++)
			cout << "X";
		cout << endl;

	}


}

void vx(int N) {

	for (int w = 0; w < N; w++)
	{
		for (int k = 0; k < 2*(N-1) + 1; k++)
		{

			if (w == k || k == 2*(N-1)-w)
				cout << "x"; 
			else 
				cout << "-";
		}
		cout << endl;
	}

}

void color(const int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);

}
