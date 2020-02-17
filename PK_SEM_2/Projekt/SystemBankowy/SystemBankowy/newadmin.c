#include "newadmin.h"
#include "stringsop.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "adminlist.h"
#include "list.h"
#include "extra.h"



void createadmin(Admin_list * list)
{
	if (admincode())
		return; //wyjscie z tworzenia konta
	Logindata tmp;

	tmp.login_attemps = 0; //ustawienie poczatkowej wartosci 

	if (createloginadmin(list, &tmp)) //tworzenie loginu i sprawdzanie czy jest dostepny
		return;//wyjscie z tworzenia konta

	if(createpasswordadmin(&tmp)) //tworzenie odpowiedniego hasla
		return;//wyjscie z tworzenia konta
	
	addnewadmin(list, tmp); //dodanie administratora do listy administratorow

}


int admincode()
{
	char buffer[12]; 
	while (1)
	{
		loadstring(11, buffer, "Podaj kod administratora: ", password); //wczytywanie strgina o okreslonej dlugosci

		if (strcmp(buffer, "111") == 0)
			return 0;//podanie poprawnego kodu
		else
		{
			printf("Podany kod jest nieprawidlowy");
			if (breakout())
				return 1;// wyjscie z tworzenia konta
			
		}
	}
}

int createloginadmin(Admin_list *list ,Logindata *tmp)
{
	while(1)
	{
		loadstring(LOGIN_L - 1, tmp->login, "Podaj login: ", alfanumeric);
		if (strlen(tmp->login) < 4)
		{
			printf("Podany login jest za krotki (min.5 znakow)");
			if (breakout())
				return 1;
		}
		else
		{
			if (findloginadmin(list, tmp->login) != NULL)
			{
				printf("Podany login juz istnieje");
				if (breakout())
					return 1;
			}
			else
				return 0;
			
		}
	}
}


int createpasswordadmin(Logindata *tmp)
{
	char buff1[PASSWORD_L];
	char buff2[PASSWORD_L];

	while (1)
	{

		loadstring(PASSWORD_L - 1, buff1, "Wpisz haslo: ", password);
		if (strlen(buff1) < 3)
		{
			printf("Podane haslo jest za krotkie");
			if (breakout())
				return 1;

			continue;

		}
		loadstring(PASSWORD_L - 1, buff2, "powtorz haslo: ", password);
		if (strcmp(buff1, buff2) == 0)
			break;
		else
		{
			printf("Podane hasla nie pasuja do siebie");
			if (breakout())
				return 1;

		}

	}
	strcpy(tmp->password, buff1);
	return 0;
}
