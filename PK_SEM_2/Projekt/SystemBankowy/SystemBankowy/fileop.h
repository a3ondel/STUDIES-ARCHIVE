#ifndef fileop_H
#define fileop_H

#include "structures.h"

//------------------USER FILES------------------------------

/*
Zapis listy uzytkownikow do pliku(zaszyfrowane dane) 
*/
void userdatasave(User_list *userlist);

/*
Pobieranie listy uzytkownikow z pliku (odszyfrowane)
*/
void userdataload(User_list *userlist);
//------------------ADMIN FILES------------------------------

/*
Pobieranie listy administratorow z pliku (odszyfrowane)
*/
void admindataload(Admin_list *userlist);

/*
Zapis listy administratorow do pliku (odszyfrowane)
*/
void admindatasave(Admin_list *userlist);
//-------------------HISTORY FILES---------------------------

/*
Pobieranie listy z historia przelewow z pliku
*/
void hs_savehistory(TransfersHis *list, char *login);

/*
Zapisywanie listy z historia przelewow do pliku
*/
void hs_loadhistory(TransfersHis *list, char *login);




#endif 
