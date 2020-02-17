#ifndef admin_H
#define admin_H
#include "structures.h"

/*
Funckja uruchamiajaca tryb administratora
*/
void adminmode(Admin_list *alist, User_list *ulist);

/*
Funkcja sluzaca do weryfikacji danych logowania administratora.
Zwraca NULL jezeli logowanie nie powiedzie sie
*/
Admin * loginadmin(Admin_list * list);

/*
Pobieranie loginu oraz sprawdzanie czy nie jest zajety
NULL jezeli login jest 
*/
Admin * loginveradmin(Admin_list *list, char *buffer);

/*
Pobieranie hasla dla administratora i jego weryfikacja
*/
int passveradmin(Admin* user, char *buffer);


#endif // !admin_H
