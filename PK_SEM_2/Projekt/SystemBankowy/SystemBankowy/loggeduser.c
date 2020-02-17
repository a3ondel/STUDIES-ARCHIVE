#include "loggeduser.h"

#include "print.h"
#include "extra.h"
#include "user.h"
#include "stringsop.h"

#include "list.h"

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include "fileop.h"

#include <Windows.h>

void loggeduser(User_list *list, User *loggeduser)
{
	char tmp = '0';
	//loggeduser->data.balance = 1000;
	do {
		printloggeduser();

		switch (getkeyres('1', '4'))
		{
		case '1': us_info(loggeduser);

			break;
		case '2': us_transfer(list,loggeduser);

			break;
		case '3': us_history(loggeduser);
			break;

		case '4': tmp = '1';
		}
	} while (tmp == '0');

}

void us_info(User *user)
{
	printbalance(user->data.balance);
	printban(user->data.logindata.login);
	//...
	waitforkey();
}

void us_transfer(User_list *ulist,User * user)
{
	char ban[21];
	char login[LOGIN_L];
	User *reciver=NULL;
	char ammount[11];
	long long int ammount64;
	while (1)
	{
		loadstring(20, ban, "Podaj nr rachunku na ktory chesz wykonac przelew: ", numbers);
		bantonick(ban, login);
		//strcpy(login, "aaabbb3981");
		reciver = findlogin(ulist, login);
		if (reciver == user)
		{
			printf("Nie mozesz wyslac przelwu na swoje konto");
			if (breakout())
				return;
		}
		else if (reciver == NULL)
		{
			printf("Podany nr rachunku nie istnieje");
			if (breakout())
				return;
		}
		else
			break;
	}
	
	while (1)
	{
		loadstring(10, ammount, "Podaj kwote przelewu: ", numbers);
		 ammount64= atoll(ammount);

		if (ammount64 > user->data.balance)
		{
			system("cls");
			printf("Za malo srodkow na koncie");
			if (breakout())
				return;
		}
		else
		{
			reciver->data.balance += ammount64;
			user->data.balance -= ammount64;
			us_makehistory(reciver,user, ammount64);
			printf("Przelew zrealizowany");
			waitforkey();
			return;
		}
	}
}


void us_makehistory(User *sender, User *reciver,  long long int ammount)
{

	TransfersHis list;
	Transferdata data;
	gettime(data.date);
//------USTAWIANIE INFORMACJI W TYCZMASOWEJ STRUKTURY---------------
	strcpy(data.name, sender->data.userdata.name);
	strcpy(data.surrname, sender->data.userdata.surrname);
	data.adress = sender->data.adress;
	data.type = 0;
	data.accountmoney = sender->data.balance;
	data.transfermoney = ammount;
//------------DODANIE NOWEGO PRZELEWU DO HISTORII--------------------
	hs_loadhistory(&list, sender->data.logindata.login);  
	hs_addtransfer(&list, data);
	hs_savehistory(&list, sender->data.logindata.login);
	hs_freememn0his(&list);
//------USTAWIANIE INFORMACJI DO TYCZMASOWEJ STRUKTURY---------------

	strcpy(data.name, reciver->data.userdata.name);
	strcpy(data.surrname, reciver->data.userdata.surrname);
	data.adress = reciver->data.adress;
	data.type = 1;
	data.accountmoney = reciver->data.balance;
	data.transfermoney = ammount;

//------------DODANIE NOWEGO PRZELEWU DO HISTORII--------------------
	hs_loadhistory(&list, reciver->data.logindata.login);
	hs_addtransfer(&list, data);
	hs_savehistory(&list, reciver->data.logindata.login);
	hs_freememn0his(&list);
		
}

void us_history(User *user)
{
	TransfersHis listtmp;
	Onetransfer *onetransfer;
	hs_loadhistory(&listtmp, user->data.logindata.login);
	onetransfer = listtmp.phead;
	int i = 1;
	system("cls");
	while (onetransfer)
	{
		printonetransfer(&onetransfer->transferdata,i);
		i++;
		onetransfer = onetransfer->pnext;
	}
	hs_freememn0his(&listtmp);
	waitforkey();

}