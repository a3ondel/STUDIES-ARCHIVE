#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;
const int m = 11;
int tab[m][m]{};
void f(int k);
void f1(int k);
void f2(int k);
void f3(int k);
void f4(int k);
void wypisz();
void color(const int a);

int main()
{
	f3(0);
	wypisz();


	
	return 0;
}
void f4(int k)
{
	if (k <= m)
	{

		for (int i = k; i < m-k; i++)
		{
			for (int j = k; j < m-k; j++)
			{
				tab[i][j] = k+1;
				
			}
		}
		f4(k + 1);
	}


}
void f3(int k) 
{
	if (k < m / 2+m%2)
	{
		for (int i = 0; i < m-2*k; i++)
		{
			tab[k + i][k] = k+1;
			tab[k][k + i] = k + 1;
			tab[m - k - 1 - i][m - k - 1] = k + 1;
			tab[m - k - 1][m - k - i - 1] = k + 1;
			wypisz();
		}
		f3(k + 1);
	}
}

void f2(int k)
{
	color(12);
	if (k <= m * m)
	{
		tab[m- (k / m)-1][m- (k % m)] = k;
		wypisz();
		f2(k + 1);
	}

}
void f1(int k)
{
	
	color(12);
	if (k <= m * m )
	{
		tab[(k-1) / m][(k-1) % m] = k;
		wypisz();
		f1(k + 1);
	}
	
}
void f(int k)
{
	color(12);
	wypisz();
	if (k <= m)
	{
		
		tab[k - 1][k - 1] = k;
		wypisz();
		for (int i = 0; i < k ; i++)
		{
			
			tab[k - 1][k-i-1] = k;
			tab[k-i-1][k - 1] = k;
			wypisz();
		}
		f(k + 1);
	}

}

void wypisz()
{
	system("cls");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tab[i][j] != 0) color(tab[i][j]%15 +1);
			cout << setw(4) << tab[i][j];
		}
		cout << "\n";
	}
	Sleep(150);
	//_getch();
}
void color(const int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);

}