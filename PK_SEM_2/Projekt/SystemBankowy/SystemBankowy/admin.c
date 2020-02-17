#include "admin.h"
#include "loggedadmin.h"
#include "newadmin.h"
#include "list.h"
#include "stringsop.h"
#include "extra.h"
#include "print.h"
#include <stdio.h>

//#include <string.h>

void adminmode(Admin_list *alist, User_list *ulist)
{
	Admin *tmp = NULL;
	char bol = '0';
	do
	{
		printadminmenu();
		switch (getkeyres('1', '3'))
		{
		case '1': if ((tmp = loginadmin(alist)) != NULL)
				loggedadmin(alist, ulist, tmp);
			break;
		case '2': createadmin(alist);
			break;
		case '3': bol = '1';
			break;
		}
	} while (bol == '0');

}

Admin * loginadmin(Admin_list * list)
{
	char buffer[PASSWORD_L];
	Admin *user=NULL;

	if (!(user = loginveradmin(list, buffer)))
		return NULL;//wyjscie

	if (user->logindata.login_attemps > 2)
	{
		printblocked();
		return NULL;//wyjscie
	}

	if (!(passveradmin(user, buffer)))
		return NULL;//wyjscie
	else
	{
		printf("Udalo sie zalogowac");
		waitforkey();
		return user; //zalogowano
	}

}


int passveradmin(Admin* user, char *buffer)
{
	do
	{
		loadstring(PASSWORD_L - 1, buffer, "Wpisz haslo: ", password);
		if (strcmp(buffer, user->logindata.password) == 0)
		{

			user->logindata.login_attemps = 0;
			return 1;//wejscie do menu zalogowanego admina
		}
		else
		{
			user->logindata.login_attemps++;

			printwrongpassword(user->logindata.login_attemps);
			
			if (breakout())
				return 0;//przerwanie logowania
		}
	} while (user->logindata.login_attemps < 3);

	printblocked();
	return 0;
}



Admin * loginveradmin(Admin_list *list, char *buffer)
{
	Admin *user;
	do {
		loadstring(LOGIN_L - 1, buffer, "Wpisz login: ", alfanumeric);

		user = findloginadmin(list, buffer);
		if (user == NULL)
		{
			printf("Podany login nie istnieje");
			if (breakout())
				return 0;//wyjscie
		}

	} while (user == NULL);

	return user;
}