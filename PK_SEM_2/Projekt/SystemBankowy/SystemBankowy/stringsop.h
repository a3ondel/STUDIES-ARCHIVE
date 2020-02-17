#ifndef stringsop_H
#define stringsop_H

typedef int(*restrictions)(char);

/*
Funkcja wczytujaca string o zadanej maksymalnej dlugosci, ogranicziczonych znakach. Dodatkowo wypisuje podany komunikat.
*/
void loadstring(int max_characters, char *dest, char *text,restrictions);

/*
funkcja usuwajaca spacje ze stringa tmp i kopiujaca otrzymany ciag do bufora
*/
void deletespace(char *tmp, char *buff);


/*
Funkcja ograniczajaca pobierane znanki
*/
int password(char tmp);

/*
Funkcja ograniczajaca pobierane znanki
*/
int letters(char tmp);

/*
Funkcja ograniczajaca pobierane znanki
*/
int alfanumeric(char tmp);

/*
Funkcja ograniczajaca pobierane znanki
*/
int alfanumericsp(char tmp);

/*
Funkcja ograniczajaca pobierane znanki
*/
int numbers(char tmp);


#endif 
