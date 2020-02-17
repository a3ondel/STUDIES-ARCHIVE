#include "utility.h"


int get_padding(int width)
{
	return ((4 - (width * sizeof(PIXEL)) % 4) % 4);//Obliczanie ile bajtow nalezy dopisac do pliku zeby jedna linia obrazka  
												   //skladala sie z n bajtow, gdzie n jest podzielne przez 4
												   //ostatnia operacja reszty z dzielenia przez 4 wystepuje zeby nie dopisywac
												   //niepotrzebnych bajtow (tj. 4)

}

