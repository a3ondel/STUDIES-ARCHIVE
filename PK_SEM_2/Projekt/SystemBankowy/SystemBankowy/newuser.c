#include "newuser.h"
#include "stringsop.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "extra.h"


void createuser(User_list *list)
{
	Data tmp;

	if (nu_dataload1(&tmp))
		return;

	nu_createnick(list, &tmp);

	if (nu_createpassword(&tmp))
		return;

	if (nu_dataload2(&tmp))
		return;

	tmp.logindata.login_attemps = 0;
	tmp.balance = 50;

	addnewuser(list, tmp);

	printf("Twoj login to %s\n", tmp.logindata.login);
	
	waitforkey();

}

int nu_loadname(Data *tmp,char *buffer)
{
	while (1)
	{
		loadstring(NAME_L - 1, tmp->userdata.name, "Podaj imie: ", letters);
		deletespace(tmp->userdata.name, buffer);

		if (strlen(buffer) > 2)
			return 0; //podane imie jest poprawne
		else
		{
			printf("Podane imie jest za krotkie");
			if (breakout())
				return 1;
		}
	}
}

int nu_loadsname(Data *tmp, char *buffer)
{
	while (1)
	{
		loadstring(SURNAME_L - 1, tmp->userdata.surrname, "Podaj nazwisko: ", letters);
		deletespace(tmp->userdata.surrname, buffer);
		if (strlen(buffer) > 2)
			return 0;
		else
		{
			printf("Podane nazwisko jest za krotkie");
			if (breakout())
				return 1;
		}
	}
}

int nu_loadpesel(Data *tmp, char *buffer)
{
	while (1)
	{
		loadstring(PESEL_L - 1, tmp->userdata.pesel, "Podaj pesel: ", numbers);
		if (nu_validatepesel(tmp->userdata.pesel))
			return 0;
		else
		{
			printf("Podany nr pesel jest nieprawidlowy");
			if (breakout())
				return 1;
		}
	}
}

int nu_dataload1(Data *tmp)
{
	char buff[50];
	
	if (nu_loadname(tmp, buff))
		return 1;

	if (nu_loadsname(tmp, buff))
		return 1;
	
	if (nu_loadpesel(tmp, buff))
		return 1;

	return 0; //pop
}


int nu_createpassword(Data *tmp)
{
	char buff1[PASSWORD_L];
	char buff2[PASSWORD_L];

	while (1)
	{

		loadstring(PASSWORD_L-1, buff1, "Wpisz haslo: ", password);
		if (strlen(buff1) <3)
		{
			printf("Podane haslo jest za krotkie");

			if (breakout())
				return 1;

			continue;
		}
		loadstring(PASSWORD_L-1, buff2, "powtorz haslo: ", password);
		
		if (strcmp(buff1, buff2) == 0)
			break;
		else
		{		
			printf("Podane hasla nie pasuja do siebie");
			if (breakout())
				return 1;

		}
	}
	strcpy( tmp->logindata.password,buff1);
	return 0;
}

int nu_cityload(Data *tmp)
{
	while (1)
	{
		loadstring(CITY_L - 1, tmp->adress.city, "Podaj nazwe miasta: ", letters);
		if (strlen(tmp->adress.city) > 1)
			return 0;
		else
		{
			printf("Podana nazwa jest za krotka");
			if (breakout())
				return 1;
		}
	}
}

int nu_streetload(Data *tmp)
{
	while (1)
	{
		loadstring(STREET_L - 1, tmp->adress.street, "Podaj nazwe ulicy: ", alfanumeric);
		if (strlen(tmp->adress.street) > 0)
			return 0;
		else
		{
			printf("Podana nazwa ulicy jest nieprawidlowa");
			if (breakout())
				return 1;
		}

	}
}

int nu_honumload(Data *tmp)
{
	while (1)
	{
		loadstring(HOUSE_L - 1, tmp->adress.house_number, "Podaj numer mieszkania: ", alfanumericsp);
		if (strlen(tmp->adress.house_number) > 0)
			return 0;
		else
		{
			printf("Podany numer jest nieprawidlowy");
			if (breakout())
				return 1;
		}
	}
}

int nu_dataload2(Data *tmp)
{
	if (nu_cityload(tmp))
		return 1;

	if (nu_streetload(tmp))
		return 1;

	if (nu_honumload(tmp))
		return 1;

	return 0;
}


int nu_validatepesel(char *pesel)
{
	int multiplier[11] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3,0 }; //Wagi poszczegolnych cyfr numeru pesel, wykorzystywane 
														 // do obliczenia sumy kontrolnej.										
	int checksum = 0; //Suma kontrolna

	int i;
	for (i = 0; i < 11; i++)	//petla odpowiedzialna za przechodzenie po pojedynczych elementach tablicy
	{
		if (pesel[i]<'0' || pesel[i]>'9')
			return 0; //Aktualnie sprawdzany znak jest bledny.

		checksum += (multiplier[i] * (pesel[i] - '0')) % 10;    //Obliczanie wartosci do dodania do sumy kontrolnej.
																	 // Dzieki reszcie z dzielenia  brana pod uwage jest tylko 
																	// liczba jednosci			
	}
	checksum = 10 - (checksum % 10); //oblicznanie ostatecznej wartosci sumy kontrolnej


	if (pesel[10] - '0' != checksum)		//sprawdzenie czy ostatnia cyfra nr pesel jest poprawna
		return 0; //Numer pesel jest bledny.
	else
		return 1; //Numer pesel jest poprawny.
}

void nu_createnick(User_list *list,Data *data)
{
	srand(time(NULL));
	char buffer[50];
	char numbers[5];
	char nametmp[3];
	char snametmp[3];
	
	deletespace(data->userdata.name, buffer);
	strncpy(nametmp, buffer, 3);

	deletespace(data->userdata.surrname, buffer);
	strncpy(snametmp, buffer, 3);

	int tmp;

	 do
	 {
		 memset(buffer, 0, LOGIN_L);
		 strncpy(buffer, nametmp, 3);
		 strncat(buffer, snametmp,3);
		 tmp = rand() % 10000;
		 _itoa(tmp, numbers, 10);

		 strcat(buffer, numbers);

	 } while (findlogin(list,buffer)!=NULL);

	 strcpy(data->logindata.login, buffer);
}


