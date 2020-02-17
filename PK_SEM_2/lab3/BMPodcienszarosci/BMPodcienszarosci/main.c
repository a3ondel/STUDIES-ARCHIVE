/*
Autor: Adam Trznadel
Lab3
PK2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "read.h"
#include "write.h"
#include "utility.h"
#include "filters.h"

int main()
{
	BMP *imagefile=(BMP *)malloc(sizeof(BMP)); //rezerwowanie pamieci 
	char filename[100];
	printf("Podaj nazwe pliku do odczytu: ");
	scanf("%s", filename);

	switch (read_file(filename, imagefile)) //wczytywanie pliku bmp
	{
	case -1: printf("Nie udalo sie otworzyc pliku");
		break;
	case 0: printf("Nieobslugiwany plik");
		break;

	case 1: 
			ColortoGrayscale(imagefile->imgarray, (int)imagefile->imghead.width_px, (int)imagefile->imghead.height_px); //zmiana kolorow obrazka
			
			printf("Podaj nazwe do zapisu: ");
			scanf("%s", filename);

			if (write_file(filename, imagefile))
				printf("Poprawny zapis");
			else
				printf("Nie udalo sie zapisac pliku");

			free(imagefile->imgarray); //zwalnianie pamieci 
		break;
		
	}
	 
	free(imagefile);		   //zwalnianie pamieci
	

	return 0;
}