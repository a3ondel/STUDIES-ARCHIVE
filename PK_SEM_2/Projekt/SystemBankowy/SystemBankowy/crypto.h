#ifndef crypto_H
#define crypto_H
#include "structures.h"

/*
Funkcja szyfrujaca liczbe
*/
void encrypt_number(long long int *number);
void encrypt_number_4(int *number);


/*
Funkcja odszyfrowujaca liczbe
*/
void decrypt_number(long long int *number);
void decrypt_number_4(int *number);
/*
Funkcja szyfrujaca zadana dlugosc ciagu znakow
*/
void encrypt_string(char * string, int lenght);

/*
Funkcja odszyfrowujaca zadana dlugosc ciagu znakow
*/
void decrypt_string(char * string, int lenght);


/*
Funkcja szyfrujaca strukture Data
*/
void encrypt_data(Data * data);

/*
Funkcja szyfrujaca strukture Logindata
*/
void encrypt_logindata(Logindata *data);

/*
Funkcja odszyfrowujaca strukture Data
*/
void decrypt_data(Data * data);

/*
Funkcja odszyfrowujaca strukture Logindata
*/
void decrypt_logindata(Logindata *data);

/*
Funkcja odszyfrowujaca strukture Transferdata
*/
void decrypt_tranferdata(Transferdata *data);


/*
Funkcja odszyfrowujaca strukture Transferdata
*/
void encrypt_tranferdata(Transferdata *data);
#endif // !crypto_H

