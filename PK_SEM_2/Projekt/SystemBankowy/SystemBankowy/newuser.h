#ifndef  newuser_H
#define  newuser_H
#include "structures.h"


/*
Funkcja tworzaca nowego uzytkownika
*/
void createuser(User_list *list);

/*
Funkcja wczytujaca podstawowe dane uzytkownika takie jak imie nazwisko oraz pesel
wczytane dane sluza do wygenerowania nicku do logowania
*/
int nu_dataload1(Data *tmp);

/*
Wczytywanie i weryfikowanie imienia
*/
int nu_loadname(Data *tmp, char *buffer);

/*
Wczytywanie i weryfikowanie nazwiska
*/
int nu_loadsname(Data *tmp, char *buffer);

/*
Wczytywanie i wstepne weryfikowanie nr pesel
*/
int nu_loadpesel(Data *tmp, char *buffer);

/*
Funckja pobierajaca adres nazwe ulicy i numeru domu
*/
int nu_dataload2(Data *tmp);

/*
Wczytywanie i weryfikowanie nazwy ulicy
*/
int nu_cityload(Data *tmp);

/*
Wczytywanie i weryfikowanie nazwy ulicy
*/
int nu_streetload(Data *tmp);

/*
Pobieranie i weryfikowanie numeru domu/mieszkania/itp
*/
int nu_honumload(Data *tmp);

/*
Pobieranie i weryfikowanie hasla 
*/
int nu_createpassword(Data *tmp);

/*
Weryfikacja podanego nr pesel
*/
int  nu_validatepesel(char *pesel);

/*
Tworzenie nicku dla nowego uzytkownika
*/
void nu_createnick(User_list *list, Data *data);

#endif 

