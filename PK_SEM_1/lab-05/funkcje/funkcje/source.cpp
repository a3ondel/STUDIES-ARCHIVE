#include <iostream>
#include <algorithm>
//#include <utility>
#include <string>
using namespace std;
float f(float x)
{

	return x*x ;
}
float calkowanie(float a, float b,int N)
{
	float pole = 0;
	for (float i = a; i < b; i += (b - a)/N)
	{
		pole += (f(i) + f(i + (b - a) / N))*((b - a) / N) / 2;

	}
	return pole;
}

void sort_wyb(const int N, int tab[])
{
	int tmp_i = 0;
	for (int  i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{


			if (tab[i] > tab[j])
			{
				swap(tab[i], tab[j]);

			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << tab[i] << " ";

	}


}
int main()
{
	int i;
	string s;
	cin >> i;
	cin.get();
	getline(cin, s);
	cout << i;
	cout << endl << s;
	const int N = 8;
	int tab[N]{ 3,1,5,7,4,5,7,3 };
	sort_wyb(N, tab);
	//cout<<calkowanie(0, 10, 10000);
	return 0;	
}