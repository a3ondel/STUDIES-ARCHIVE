#ifndef user_H
#define user_H

#include "structures.h"

//void transfer(User_list *list, User *user);

/*
Funckja uruchamiajaca tryb uzytkownika
*/
void usermode(User_list *ulist);

/*
Funkcja logujaca uzytkownia, jezeli logowanie powiedzie sie zwracany jest adres na lisicie.
Nieudane logowanie powoduje zwrocenie NULL
*/
User* login(User_list *list);

/*
Funkcja wczytujaca haslo i weryfikujaca czy pasuje do danego uzytkownika
*/
int passver(User* user, char *buffer);

/*
Funkcja pobierajaca i weryfikujaca czy podany login istnieje,
zwraca adres uzytkownika lub NULL jezeli uztykownik nie zostal znaleziony
*/
User * loginver(User_list *list, char *buffer);

/*
zamiana nicku na bank account number
*/
void nicktoban(char *login,char *buffer);


/*
zamiana bank account number na nick
*/
void bantonick(char *ban, char *buffer);



#endif // !account_H
