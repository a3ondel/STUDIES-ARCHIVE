#include "utility.h"

/*
czyszczenie ekranu konsoli
*/
void cls()
{
	system("cls");

}

/*
wczytywanie informacji z pliku
*/
void fileload(FILE *File, coffe_machine *data)
{
	
	fscanf_s(File, "%d %d %d %d %d", &data->coffe_amount, &data->water_amount, &data->milk_amount, &data->coffe_power, &data->base_size);

}

/*
zapisywanie informacji o zasobach oraz ustawien do pliku
*/
void filesave(FILE *File, coffe_machine *data)
{
	fprintf_s(File,"%d\n%d\n%d\n%d\n%d", data->coffe_amount, data->water_amount, data->milk_amount, data->coffe_power, data->base_size);

}


