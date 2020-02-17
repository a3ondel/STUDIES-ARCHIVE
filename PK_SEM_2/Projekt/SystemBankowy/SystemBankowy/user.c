#include "user.h"
#include "stringsop.h"
#include <string.h>

#include "list.h"

#include "extra.h"
#include <stdio.h>
#include <Windows.h>
#include "newuser.h"
#include "loggeduser.h"
#include "print.h"

void usermode(User_list *ulist)
{
	User *tmp = NULL;
	char bol = '0';
	do
	{
		printusermenu();
		switch (getkeyres('1', '3'))
		{
		case '1': if (tmp = login(ulist))
			loggeduser(ulist, tmp);
			break;
		case '2': createuser(ulist);
			break;
		case '3': bol = '1';
			break;
		}
	} while (bol == '0');
}

User* login(User_list * list)
{
	char buffer[PASSWORD_L];
	User *user;
	
	if (!(user=loginver(list, buffer)))
		return NULL;

	if (user->data.logindata.login_attemps > 2)
	{
		printblocked();
		return NULL;//wyjscie
	}

	if (!(passver(user, buffer)))
		return NULL;
	else
	{
		printf("Udalo sie zalogowac");
		waitforkey();
		return user;
	}

}


int passver(User* user, char *buffer)
{
	do
	{
		loadstring(PASSWORD_L - 1, buffer, "Wpisz haslo: ", password);
		if (strcmp(buffer, user->data.logindata.password) == 0)
		{

			user->data.logindata.login_attemps = 0;
			return 1;//wejscie do menu zalogowanego
		}
		else
		{
			user->data.logindata.login_attemps++;
			
			printwrongpassword(user->data.logindata.login_attemps);

			if (breakout())
				return 0;
		}
	} while (user->data.logindata.login_attemps < 3);

		printblocked();
		return 0;
}

User * loginver(User_list *list,char *buffer)
{
	User *user;
	do {
		loadstring(LOGIN_L - 1, buffer, "Wpisz login: ", alfanumeric);

		user = findlogin(list, buffer);
		if (user == NULL )
		{
			printf("Podany login nie istnieje");
			if (breakout())
				return 0;//wyjscie
		}

	} while (user == NULL);

	return user;
}

void nicktoban(char * login,char *buffer)
{
	
	char tmp[3];
	memset(buffer, 0, 21);
	
	for (int i = 0; i < 6; i++)
	{
		_itoa((int)login[i]-50, tmp, 10);
		strcat(buffer, tmp);

	}
	for (int i = 6; i < LOGIN_L-1; i++)
	{
		_itoa((int)login[i] + 10+i , tmp, 10);
		strcat(buffer, tmp);
	}
	
}

void bantonick(char *ban, char *buffer)
{
	char tmp[3];
	memset(tmp, 0, 3);

	for (int i = 0; i < 11; i+=2) 
	{
		strncpy(tmp, &ban[i], 2);
		buffer[i / 2] = ((char)atoi(tmp) + 50);
		
	}
	

	for (int i = 12; i < 21; i+=2)
	{
		strncpy(tmp, &ban[i], 2);
		buffer[i/2]= (char)(atoi(tmp) - i / 2 - 10);		
	}
	buffer[10] = '\0';

}

