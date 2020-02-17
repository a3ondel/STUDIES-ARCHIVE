#include <iostream>
#include "Figura.h"
#include "Szachownica.h"
#include "Wieza.h"
#include "Goniec.h"

using std::cout;
using std::endl;

int main()
{
	
	Szachownica drewniana;
	drewniana.display();
	cout << "\n-------------\n";
	Wieza wiez;
	wiez.set(&drewniana, 1, 1);
	drewniana.display();
	cout << "\n-------------\n";
	//wiez.range();
	drewniana.display();
	
	cout << "\n-------------\n";
	drewniana.display();

	Goniec gon;
	gon.set(&drewniana, 2, 3); // testowane od dla calej przekatnej oraz kliku losowych punktow
	cout << "\n-------------\n";
	drewniana.display();
	cout << "\n-------------\n";
	//gon.range();
	//drewniana.display();
	drewniana.showRange();
	

	return 0;

}
