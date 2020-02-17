#include "stringsop.h"
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "print.h"
#define BACKSPACE 8
#define ENTER 13



void loadstring(int max_characters, char * dest,char *text,restrictions function)
{
		int i = -1;		
		char tmp;
		char buff[50];
		memset(buff, 0, 50);

		printstring(buff,text);

		do
		{
			tmp = _getch();
			if (tmp != BACKSPACE)
			{
				if (i < (max_characters - 1) &&function(tmp))
				{
						i++;
						buff[i] = tmp;
				}
			}
			else 
				if (i > -1)
				{
					buff[i] = '\0';
					i--;
				}
			
			if (function != password)
				printstring(buff, text);
			else
				printpassword(i + 1, text);

		} while (tmp != '\n'&&tmp!=ENTER);
		
		strcpy(dest, buff);
		system("cls");
}

int password(char tmp)
{
	return (tmp >= ' '&&tmp <= '}');
}

int letters(char tmp)
{
	return ((tmp >= 'a'&&tmp <= 'z') || (tmp >= 'A'&&tmp <= 'Z') || tmp == ' ');
}

int numbers(char tmp)
{
	return (tmp >= '0'&&tmp <= '9');
}

int alfanumeric(char tmp)
{
	return ((tmp >= 'a'&&tmp <= 'z') || (tmp >= 'A'&&tmp <= 'Z') || tmp == ' ' || (tmp >= '0'&&tmp <= '9'));
}

int alfanumericsp(char tmp)
{
	return ((tmp >= 'a'&&tmp <= 'z') || (tmp >= 'A'&&tmp <= 'Z') || tmp == ' ' || (tmp >= '0'&&tmp <= '9') || (tmp =='/')||(tmp=='\\'));
}

void deletespace(char *tmp,char *buff)
{

	int i = 0;
	int j = 0;
	
	//memset(buff, 0, 50);

	while (tmp[j] != '\0')
	{
		if (tmp[j] != ' ')
		{
			buff[i] = tmp[j];
			i++;
		}
		j++;
	}
	buff[i] = '\0';

}

	


