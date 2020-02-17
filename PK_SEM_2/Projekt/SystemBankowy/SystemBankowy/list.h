#ifndef list_H
#define list_H

#include "structures.h"
//ADMIN
//-------------------------------------ADMINLIST---------------------------

/*
funkcja dodajaca elemnt do listy administratorow
*/
void addnewadmin(Admin_list *admin_list, Logindata logindata);

/*
Funkcja wyszukujaca aministratora na lisice
*/
Admin * findloginadmin(Admin_list * list, char * login);

/*
Funkcja usuwajaca element z lity administratorow 
*/
void deleteadmin(Admin_list *list, Admin *admin);

/*
Funkcja zwlaniajaca pamiec zajmowana przez liste, oraz zerujaca wartosci
*/
void freememn0admin(Admin_list *list);

//---------------------------------------USERLIST--------------------------

/*
Funkcja dodajaca nowy element do listy uzytkownikow
*/
void addnewuser(User_list *userlist, Data data);

/*
Funkcja usuwajaca element z listy
*/
void deleteuser(User_list *list, User *user);

/*
Funkcja wyszukjaca uzytkownika w liscie
*/
User * findlogin(User_list *list, char *login);

/*
Funkcja zwlaniajaca pamiec oraz zerujaca wartosci struktury
*/
void freememn0(User_list *list);
//-----------------------------------HISTORYLIST-------------------

/*
Funkcja dodajace jeden przelew do listy przelewow (na koniec)
*/
void hs_addtransfer(TransfersHis *list, Transferdata data);

/*
Funkcja zwalniajaca pamiec listy historii
oraz zerujaca zawartosc
*/
void hs_freememn0his(TransfersHis *list);



#endif // !list_H
