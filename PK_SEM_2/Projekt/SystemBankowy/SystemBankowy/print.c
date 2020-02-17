#include "print.h"
#include <stdio.h>
#include <Windows.h>
#include "user.h"
#include <stdlib.h>
#include <string.h>

void printstring(char * tmp, char *text)
{
	system("cls");
	printf("%s%s", text, tmp);

}

void printpassword(int i_element, char *text)
{
	system("cls");
	printf("%s", text);
	for (int i = 0; i < i_element; i++)
	{
		putchar('*');
	}

}

void printadminmenu()
{
system("cls");
printf("System Bankowy dla administratorow\n");
printf("1.Zaloguj sie\n");
printf("2.Utworz konto\n");
printf("3.Wyjdz");

}

void printusermenu()
{
	system("cls");
	printf("System Bankowy dla uzytkownikow\n");
	printf("1.Zaloguj sie\n");
	printf("2.Utworz konto\n");
	printf("3.Wyjdz");

}

void printloggeduser()
{
	system("cls");
	printf("1.wyswietl dane konta\n");
	printf("2.wykonaj przelew\n");
	printf("3.Wyswietl historie przelewow\n");
	printf("4.Wyloguj");

}
void printloggedadmin()
{
	system("cls");
	printf("1.Odblokuj konto uzytkownia\n");
	printf("2.Odblokuj konto administratora\n");
	printf("3.Usun konto uzytkownika\n");
	printf("4.Usun konto administratora\n");
	printf("5.Wyswietl liste uzytkownikow\n");
	printf("6.Wyloguj");
}

void printonetransfer(Transferdata *data, int i)
{
	char balance[15];
	char transfermoney[15];
	_i64toa(data->accountmoney, balance, 10);
	_i64toa(data->transfermoney, transfermoney, 10);
	
	if (data->type == 0)
	{
		printf("%d. Przelew od %s %s %s ul.%s %s", i, data->name, data->surrname, data->adress.city, data->adress.street, data->adress.house_number);
		printf_s("\nZrealizowany %s, na kwote: %s, stan konta po przelewie: %s", data->date, transfermoney, balance);
	}
	else
	{
		printf("%d. Przelew do %s %s %s ul.%s %s", i, data->name, data->surrname, data->adress.city, data->adress.street, data->adress.house_number);
		printf_s("\nZrealizowany %s, na kwote: %s, stan konta po przelewie: %s ", data->date, transfermoney, balance);
	}
		printf("\n--------------------------------------------------------\n");
}


void printbalance(long long int balance64)
{
	char balance[15];
	_i64toa(balance64, balance, 10);
	system("cls");
	printf("Aktualny stan konta: %szl\n", balance);
}


void printban(char *username)
{
	char banwithspaces[25];
	char ban[21];
	
	nicktoban(username, ban);
	
	int j = 0;
	for (int i = 0; i < 20; i++)
	{
		if (i % 4 == 0&&i!=0)
		{
			banwithspaces[i + j] = ' ';
				j++;
		}
		banwithspaces[i + j] = ban[i];
	}
	banwithspaces[24] = '\0';

	printf("Twoj nr konta: %s", banwithspaces);
	


}
void ad_printuserlist(User_list *ulist)
{
	User *usertmp = ulist->phead;
	int i = 1;
	system("cls");
	printf("Lista uzytkownikow: ");
	while (usertmp)
	{
		printf("\n%d. %s", i,usertmp->data.logindata.login);
		i++;
		usertmp = usertmp->next;
	}
	waitforkey();

}