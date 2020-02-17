#include "extra.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <locale.h>

#define ESCAPE 27

int breakout()
{
	char tmp;
	printf("\nJesli chcesz przerwac nacisnij escape. Aby kontynuowac wcisnij dowolny klawisz");
	tmp = _getch();
	if (tmp == ESCAPE)
		return 1;
	else
		return 0;

}

void waitforkey()
{
	printf("\nAby kontynuwac nacisnij dowlny klawisz\n");
	_getch();

}
void printwrongpassword(int attemps)
{
	printf("Podane haslo jest bledne");
	waitforkey();
	system("cls");
	printf("Liczba pozostalych prob: %d", (3 - attemps));

}
void printblocked()
{
	system("cls");
	printf("Twoje konto jest zablokowane skontatktuj sie z administratorem");
	waitforkey();
}

char getkeyres(char from, char to)
{
	char tmp = 0;
	while (tmp<from || tmp>to)
	{
		tmp = _getch();
	}
	return tmp;
}

void gettime(char *buffer)
{

	time_t sec;
	struct tm *wsk_strukt;
	setlocale(LC_ALL, "pl_PL");   // przystosowanie do warunkow polskich

	time(&sec);
	wsk_strukt = localtime(&sec);
	strftime(buffer, 100, "%c", wsk_strukt);   // tutaj %c oznacza datê i czas
}