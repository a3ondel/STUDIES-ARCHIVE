#ifndef print_H
#define print_H
#include "structures.h"

//---------------------------------------------Funckje wypisujace
void printstring(char * tmp, char *text);
void printpassword(int i_element, char *text);
void printadminmenu();
void printusermenu();

void printloggeduser();
void printloggedadmin();

void printonetransfer(Transferdata *data, int i);
void printbalance(long long int balance64);
void printban(char *username);
void ad_printuserlist(User_list *ulist);
#endif // !print_h
