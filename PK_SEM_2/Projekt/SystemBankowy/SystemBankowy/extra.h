#ifndef extra_H
#define extra_H

/*
Funkcja zwracajaca oczekujaca na klikniecie klawisza w przypadku nacisniacia klawisza escape zwraca 1
w przeciwnym przypadku 0
*/
int breakout();

/*
Funkcja czekajaca na klawisz oraz wypisujaca komuniakt informujacy o oczekiwaniu na wcisniecie klawisza
*/
void waitforkey();


void printwrongpassword(int attemps);

/*
wyswietlenie komunikatu o zablkowoanym koncie oraz czekaniu na wcisniecie klawisza 
*/
void printblocked();

/*
pobieranie wcisnietego klawisza z ograniczeniami 
*/
char getkeyres(char from, char to);

/*
Funckja ladujaca aktulany czas do bufora
*/
void gettime(char *buffer);
#endif // !extra_H
