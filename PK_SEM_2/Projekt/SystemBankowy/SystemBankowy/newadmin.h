#ifndef newadmin_H
#define newadmin_H
#include "structures.h"

/*
funkcja tworzaca konto administratora i dodajaca go do listy administratorow
*/
void createadmin(Admin_list *list);

/*
funckja wczytujaca haslo oraz weryfikujaca je 
*/
int createpasswordadmin(Logindata *tmp);

/*
Funkcja wczytujaca haslo oraz weryfikujaca je
*/
int createloginadmin(Admin_list *list,Logindata *tmp);

/*
funkcja sprawdzajaca wczytujaca i sprawdzajaca kod potrzebny do stworzenia konta administratora
*/
int admincode();

#endif
