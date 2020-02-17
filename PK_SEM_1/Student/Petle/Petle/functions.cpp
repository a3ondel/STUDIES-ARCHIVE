#include <iostream>
#include "header.h"
#include <Windows.h>
#include <cmath>
using namespace std;

void zad_1(const int W,const int K)
{
	for (int w = 0; w < W; w++)
	{

		for (int k = 0; k < K; k++)
		{

			if (w % 2)
				cout << ".";
			else
				cout << "X";
		}
		cout << "\n";
	}


}
void zad_3(const int N)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			
			if (x > (N-1) / 2&&y == x-(N/2))
				cout << "X";
			else 
				cout << ".";

		}
		cout << endl;
	}

	
}

void zad_5(const int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if  (
					(j >= i&&j<=-i+N-1) ||j<=i&&j>=-i+N-1
				)
				cout << "X"; 
			else  
				cout << ".";
		}
		cout << "\n";
	}
}
void zad_6(const int N)
{
	bool warunek = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{	
			

				
				if(
				  (y <= (N-1) / 2) &&
					(
						
						(x <= (N - 1) / 2)	&&(y<=x) || (x > (N - 1) / 2)&&(y >= -x + (N - 1) )
					
					)
				||
				  
				  (y > (N-1) / 2)&&
					(
						                    
						(x <= (N - 1) / 2)	&&(y<=-x+(N-1)) || (x > (N - 1) / 2)&&(y>=x)
					)
				)
				
				
				

				cout << "X";
			else
				cout << ".";

		}
		cout << "\n";
	}


}
void zad_10(const int N)
{
	for (int y = 0; y < N; y++)
	{

		for (int x = 0; x < N; x++)
		{
			if (
				
					(x % 2 == 0) && (y >= x) 

					||
					       
					(y % 2 == 0) && (x >= y)
				)
				cout << "X";
			else
				cout << ".";
		}
		cout << "\n";
	}

}
void zad_11(const int N) 
{
	for (int y = 0; y < N; y++)
	{
		
		for (int x = 0; x < N; x++)
		{
			if(
				(
					(x%2==0)&& // rysowanie pionowej kreski tylko na parzystych 
					(y>=x&&y<N-x)  // warunek na dlugosc tylko do polowy 
						
					|| // lub 
					
					((x>=N/2)&&(x%2==1))&& // warunek na druga polowe kwadrtatu tylko nie parzyste 
					(y>=N-x-1&&y<=x)           // dlugosc pionowej kreski (druga polowa)
				) 
				
				|| //(lub) teraz to samo tylko x zamienione miejscami z y i na odwrot 
					
				(
					(y % 2 == 0) &&
					(x >= y && x < N - y)

					|| //(lub)

					((y >= N / 2) && (y % 2 == 1)) &&
					(x >= N - y - 1 && x <= y)
				)
			)
				cout << "X";
			else
				cout << ".";
		}
		cout << "\n";
	}

}
void zad_x(const int N)
{
	for (int i = 0; i < N*N; i++)
	{
		for (int j = 0; j < N*N; j++)	
		{
			if ((j + i % (2 * N)) % (2 * N) >= N) 
				cout << ".";
			else 
				cout << "X"; 
		}
		cout << "\n";
	}



}
void zad_8(const int N)
{
	for (int i = 0; i < 2*N; i++)
	{
		for (int j = 0; j < 2*N; j++)
		{
			if ((j+((i/N)%2)*N)%(2*N)  >= N)
				cout << ".";
			else
				cout << "X";
		}
		cout << "\n";
	}



}

void zad_9(const int N)
{
	for (int i = 0; i < N*N; i++)
	{
		/*for (int k = 0; k < N; k++)
		{*/


			for (int j = 0; j < N*N; j++)
			{

				if ((j + ((i/N)%2)*N) % (2 * N) >= N)
					cout << ".";
				else
					cout << "X";
			}
			cout << "\n";
		//}
	}
}


void color(const int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);

}

/*
(x%2==0)&&
					(

					//(x<N/2)&&
				 (y>=x&&y<N-x)

					)
					|| ((x>=N/2)&&(x%2==1))&&
					(y>=N-x-1&&y<=x)

				)
*/