#ifndef loggeduser_H
#define loggeduser_H
#include "structures.h"

/*
Funkcja odpowiadajaca za wlaczanie opcji dostpenych dla uzytkownika
*/
void loggeduser(User_list *list, User *loggeduser);

/*
Wyswietlanie informacji o koncie tj. numer rachunku, stan konta, itp 
*/
void us_info(User *user);

/*
Wykownywanie przelewu na inny rachunek
*/
void us_transfer(User_list *ulist, User * user);

/*
Wyswietlanie hisotrii przelewow
*/
void us_history(User *user);

/*
Dodawanie przelewu do historii dwoch kont
*/
void us_makehistory(User *sender, User *reciver,  long long int ammount);



#endif // !loggeduser_H

