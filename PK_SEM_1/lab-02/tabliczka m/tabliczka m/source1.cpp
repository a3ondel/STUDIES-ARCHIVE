#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>
using namespace std;
void color(const int a); // funkcja kolorujaca
void tabliczka(const int X, const int Y); // tabliczka mnozenia o rozmiarach X na Y
void rros(const int N); //ciag liczb z rosnaca roznica 
int main()
{
	
	tabliczka(20, 20);

	return 0;
}

void tabliczka(const int X, const int Y)
{
	for (int y = 0; y <= Y; y++)
	{
		for (int x = 0; x <= X; x++)
		{

			if (!x)
			{
				color(9);
				cout << setw(5) << y;
			}
			else

				if (!y)
				{
					color(9);
					cout << setw(5) << x;

				}
			
				else
				{
					color(15);
					if (x == y) color(10);
					cout << setw(5) << x * y;
				}
			
		}
		cout << "\n\n";
	}
}


void color(int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);


}
void rros(const int N)
{
	int j = 0;
	for (int i = 0; i <= N; i++)
	{
		j += i;
		cout << setw(5) << j;

	}

}