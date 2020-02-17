#if !defined(F_H)
#define F_H

//pobieranie zadanej ilosci znakow do tablicy 
int load(char string[],int length);

//sprawdzanie czy podany pesel jest poprawny
int validate(char pesel[]);

//wypisywanie informacji z numeru pesel tj. plec,data urodzenia
void printinfo(char pesel[]);

//fukcja czysci bufor pobranych znakow(ma zastoswanie jezeli uzytkownik wpisze za dlugi ciag znakow)
void clear();


#endif