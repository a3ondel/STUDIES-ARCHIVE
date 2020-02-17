#include "loggedadmin.h"
#include "print.h"
#include "extra.h"
#include <stdio.h>
#include "stringsop.h"

#include "list.h"



void loggedadmin(Admin_list *alist, User_list *ulist, Admin *admin)
{
	char tmp = '0';
	
	do{
		printloggedadmin();
		switch (getkeyres('1', '6'))
		{
		case '1': ad_unlockuser(ulist);

			break;
		case '2': ad_unlockadmin(alist);

			break;
		case '3':  ad_deleteuser(ulist);
			break;

		case '4': ad_deleteadmin(alist, admin);
			break; 

		case '5': ad_printuserlist(ulist);
			break;
		case '6': tmp = '1'; //wyjscie
			break;
		}
	} while (tmp=='0');
}


void ad_unlockuser(User_list *ulist)
{
	char tmp[LOGIN_L];
	User *usertmp = NULL;
	while (1)
	{
		loadstring(LOGIN_L - 1, tmp, "Podaj nazwe uzytkownika do odblokowania konta: ", alfanumeric);
		usertmp = findlogin(ulist, tmp);
		if (usertmp != NULL)
		{
			printf("czy na pewno chcesz oblokowac konto %s",usertmp->data.logindata.login);
			if (breakout())
				return;

			usertmp->data.logindata.login_attemps = 0;
			break;
		}
		else
		{
			printf("Podany uztowkonik nie istnieje");
			if (breakout())
				return;

		}
	}
}

void ad_unlockadmin(Admin_list *alist)
{
	char tmp[LOGIN_L];
	Admin *admintmp = NULL;

	while (1)
	{
		loadstring(LOGIN_L - 1, tmp, "Podaj nick odblokowywanego konta: ", alfanumeric);
		admintmp = findloginadmin(alist, tmp);
		if (admintmp != NULL)
		{
			printf("Czy na pewno chcesz oblokowac konto %s",admintmp->logindata.login);
			if (breakout())
				return;

			admintmp->logindata.login_attemps = 0;
			break;
		}
		else
		{
			printf("Podany administrator nie istnieje");
			if (breakout())
				return;

		}
	}
}

void ad_deleteadmin(Admin_list *alist,Admin *loggedadmin)
{
	char tmp[LOGIN_L];
	Admin *admintmp = NULL;
	while (1)
	{
		loadstring(LOGIN_L - 1, tmp, "Podaj nick konta do usuniecia: ", alfanumeric);
		admintmp = findloginadmin(alist, tmp);
		
		if (admintmp == loggedadmin)
		{
			printf("Nie mozesz usunac swojego konta!");
			if (breakout())
				return;

			continue;

		}
		if (admintmp != NULL)
		{
			printf("Czy na pewno chcesz usunac konto administratora  %s", admintmp->logindata.login);
			if (breakout())
				return;
			deleteadmin(alist, admintmp);

			break;
		}
		else
		{
			printf("Podany administrator nie istnieje");
			if (breakout())
				return;
		}
	}
}

void ad_deleteuser(User_list *ulist)
{
	char tmp[LOGIN_L];
	User *usertmp = NULL;
	while (1)
	{
		loadstring(LOGIN_L - 1, tmp, "Podaj nick konta do usuniecia: ", alfanumeric);
		usertmp = findlogin(ulist, tmp);

		if (usertmp != NULL)
		{
			printf("Czy na pewno chcesz usunac konto uzytkownika %s",usertmp->data.logindata.login);
			if (breakout())
				return;
			deleteuser(ulist, usertmp);
			break;
		}
		else
		{
			printf("Podany uzytkownik nie istnieje");
			if (breakout())
				return;
		}
	}
}