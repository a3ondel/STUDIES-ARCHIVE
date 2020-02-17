#include <iostream>
#include <string>
using namespace std;
int main()
{
	//std::cout << "Witaj swiecie" << std::endl;
	int wiek;
	cout << "Podaj wiek: ";
	cin >> wiek;
	if (wiek > 0 &&  wiek <= 18 )
		cout << "mlodziak\n";
	else
		if (wiek > 18 && wiek <= 65)
			cout << "dorosly\n";
		else
			cout << "osoba starsza\n";
	return 0;
}