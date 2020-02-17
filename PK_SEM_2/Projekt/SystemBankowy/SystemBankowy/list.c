#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------ADMIN
void addnewadmin(Admin_list * admin_list, Logindata logindata)
{
	Admin * phead = admin_list->phead;

	if (phead == NULL)
	{
		phead = (Admin *)calloc(1, sizeof(Admin));
		phead->logindata = logindata;

		phead->previous = NULL;
		phead->next = NULL;

	}
	else
	{
		Admin *next = phead;
		phead = (Admin *)calloc(1, sizeof(Admin));

		phead->logindata = logindata;

		phead->previous = NULL;
		phead->next = next;

		next->previous = phead;
	}
	admin_list->accounts_count++;

	admin_list->phead = phead;

}


void deleteadmin(Admin_list *list, Admin *admin)
{
	list->accounts_count--;

	if (admin)
	{
		Admin *next = admin->next;
		Admin *prev = admin->previous;

		free(admin);

		if (admin == list->phead)
		{
			list->phead = next;

		}
		if (next)
			next->previous = prev;

		if (prev)
			prev->next = next;
	}
}


Admin * findloginadmin(Admin_list * list, char * login)
{

	Admin *tmp = list->phead;

	while (tmp)
	{
		if (strcmp(tmp->logindata.login, login) == 0)
		{
			return tmp;
		}

		tmp = tmp->next;
	}

	return NULL;
}


void freememn0admin(Admin_list *list)
{
	Admin*tmp = list->phead;
	Admin *next = tmp;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	list->phead = NULL;
	list->accounts_count = 0;

}

//---------------------------------------------USER

void addnewuser(User_list *userlist, Data data)
{

	User *phead = userlist->phead;
	if (phead == NULL)
	{
		phead = (User *)calloc(1, sizeof(User));
		phead->data = data;

		phead->previous = NULL;
		phead->next = NULL;

	}
	else
	{
		User *next = phead;
		phead = (User *)calloc(1, sizeof(User));

		phead->data = data;

		phead->previous = NULL;
		phead->next = next;

		next->previous = phead;
	}
	userlist->accounts_count++;

	userlist->phead = phead;


}


void deleteuser(User_list *list, User *user)
{
	list->accounts_count--;

	if (user)
	{
		User *next = user->next;
		User *prev = user->previous;

		free(user);

		if (user == list->phead)
		{
			list->phead = next;

		}
		if (next)
			next->previous = prev;

		if (prev)
			prev->next = next;
	}
}


User * findlogin(User_list * list, char * login)
{

	User *tmp = list->phead;

	while (tmp)
	{
		if (strcmp(tmp->data.logindata.login, login) == 0)
		{
			return tmp;
		}

		tmp = tmp->next;
	}

	return NULL;
}


void freememn0(User_list *list)
{
	User*tmp = list->phead;
	User *next = tmp;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	list->phead = NULL;
	list->accounts_count = 0;

}

//---------------------------------HISTORY---------------------

void hs_addtransfer(TransfersHis *list, Transferdata data)
{

	if (list->phead == NULL)
	{
		list->phead = (Onetransfer *)calloc(1, sizeof(Onetransfer));
		list->ptail = list->phead;
		list->phead->pnext = NULL;
		list->phead->transferdata = data;
	}
	else
	{
		Onetransfer *tmp = NULL;
		list->ptail->pnext = (Onetransfer *)calloc(1, sizeof(Onetransfer));
		list->ptail = list->ptail->pnext;
		list->ptail->transferdata = data;
		list->ptail->pnext = NULL;
	}
	list->transferscount++;
}

void hs_freememn0his(TransfersHis *list)
{
	Onetransfer*tmp = list->phead;
	Onetransfer*next = tmp;

	while (tmp)
	{
		next = tmp->pnext;
		free(tmp);
		tmp = next;
	}

	list->phead = NULL;
	list->transferscount = 0;
	list->ptail = NULL;
}
