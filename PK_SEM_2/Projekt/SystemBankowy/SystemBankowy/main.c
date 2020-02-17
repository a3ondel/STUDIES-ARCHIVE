/*
Projekt: System Bankowy
Laboratorium PK2 
Autor: Adam Trznadel
AEI INF SSI sem.2
2019

*/

#include "structures.h"
#include "fileop.h"
#include "user.h"
#include "admin.h"
#include "params.h"
#include "list.h"

//#include "vld.h"//tmp memory leak testing

int main(int n_elements, char *arg[])
{
	
	User_list userlist1;
	Admin_list adminlist1;

	admindataload(&adminlist1); //wczytywanie, odszyfrowywanie , dodawanie danych administratorow do listy(administratorow) 
	userdataload(&userlist1);  //wczytywanie, odszyfrowywanie , dodawanie danych administratorow do listy(uzytkownikow) 
	
	if (modechoose(n_elements, arg)==0) //wybieranie trybu dzialania programu
	{
		usermode(&userlist1);
	}
	else
	{
		adminmode(&adminlist1, &userlist1);
	}

	admindatasave(&adminlist1); //szyfrowanie i zapis listy administratorow do pliku
	userdatasave(&userlist1); //szyforwanie i zapis listy uzytkownikow do pliku
	freememn0(&userlist1); //zwalnianie pamieci zajmowanej przez liste administratorow
	freememn0admin(&adminlist1); //zwalnianie pamieci zajmowanej przez liste administratorow
	
	return 0;
}