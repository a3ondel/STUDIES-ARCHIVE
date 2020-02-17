#include <iostream>
#include "header.h"
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	
	
	
	/*int tab[10][10]{ 1,2,3,4 };
	int suma_w, suma_k;
	for (int w = 0; w < W; w++)
	{
		suma_w = 0;
		suma_k = 0;
		for (int k = 0; k < K; k++)
		{
			
			suma_w += tab[w][k];
			suma_k += tab[k][w];

		}


		cout << "wiersz:" << w << ". suma wartosci: " << suma_w << endl;
		cout << "kolumna:" << w << "suma: " << suma_k;
		cout << endl << endl;
	}*/
	int tab[W][K]{};
	for (int w = 0; w < 10; w++)
	{
		color(los(10, 12));
		for (int k = 0; k < 10; k++)
		{
			cout << setw(4) << tab[w][k];
		}

		cout << endl;
	}
	cout << "-------" << endl;
	zygzak(tab);

	for (int w = 0; w < 10; w++)
	{
		color(los(10, 12));
		for (int k = 0; k < 10; k++)
		{
			cout <<setw(4)<< tab[w][k];
		}

		cout << endl;
	}
	return 0;
}

