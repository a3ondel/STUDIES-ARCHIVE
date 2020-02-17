#include <iostream>

using namespace std;

int main()
{
	float BMI;

	float m;
	float h;
	cout << "Podaj twoja masa: ";
	cin >> m;
	cout << "\nPodaj twoj wzrost: ";
	cin >> h;
	BMI = m / (h *h);
	cout << "masz: ";
	cout << BMI;
	if (BMI<18.5) 
		cout << " niedowage"; 
	else if (BMI<25) 
		cout << " normalna wage"; 
	else if (BMI < 30)
		cout << " nadwage";
	else
		cout << " otylosc";
	return 0;
}