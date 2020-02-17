#include <iostream>
#include "header.h"
#include <Windows.h>
#include <random>
#include <chrono>
#include <iomanip>

int los(const int &a, const int &b)
{
	srand(time(NULL));
	return rand() % (b - a+1) + a;
}
void color(const int &a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);

}

void spirala(int tab[][K])
{
	int kierX[4]{ 1,0,-1,0 };
	int kierY[4]{ 0,1,0,-1 };
	int x = 0, y = 0;
	int kierunek = 0;
	bool zmiana;

	for (int i = 1; i <= W * K; i++)
	{
		tab[y][x] = i;

		if (x + kierX[kierunek] >= 0 && x + kierX[kierunek] < K&&y +
			kierY[kierunek] >= 0 && y + kierY[kierunek] <
			W)
		{
			if (!(tab[y + kierY[kierunek]][x + kierX[kierunek]] == 0)) kierunek++;
			
		}

		else {
			kierunek++; 
		}

		kierunek %= 4;

		x += kierX[kierunek];
		y += kierY[kierunek];
	}
}

void zygzak(int tab[][K]) 
{

	int x = 0, y = 0, kx = 1;

	for (int i = 1; i < W * K; i++)
	{
		tab[y][x] = i;
		if (x + kx == K)
		{
			kx = -1;
			y += 1;
			x += 1;
		}
		else
			if(x+kx==-1)
			{kx = 1;
			y += 1;
			x -= 1;
		}
		x += kx;
	}


}
