#include "fileop.h"
#include <stdio.h>
#include <direct.h>
#include "crypto.h"
#include "list.h"
#include <string.h>


void userdatasave(User_list *userlist)
{
	_mkdir("DATA");
	FILE *file = fopen("DATA\\users.dat","wb");
		
	int acctmp = userlist->accounts_count;
	encrypt_number_4(&acctmp);
	fwrite(&acctmp, sizeof(int), 1, file);

	User *tmpp = userlist->phead;
	Data tmpdata;
	while (tmpp)
	{
		tmpdata = tmpp->data;
		encrypt_data(&tmpdata);
		fwrite(&tmpdata, sizeof(Data), 1, file);
		tmpp = tmpp->next;
	}
	fclose(file);
}


void userdataload(User_list *userlist)
{
	FILE *file = fopen("DATA\\users.dat", "rb");
	
	int acctmp = 0;
	userlist->accounts_count = 0;
	userlist->phead = NULL;

	if (file != NULL)
	{
		fread(&acctmp, sizeof(int), 1, file);

		decrypt_number_4(&(acctmp));

		Data tmp;
		for (int i = 0; i < acctmp; i++)
		{
			fread(&tmp, sizeof(Data), 1, file);
			decrypt_data(&tmp);
			addnewuser(userlist, tmp);
		}
		fclose(file);
	}
}
	

void admindataload(Admin_list *userlist)
{
	FILE *file = fopen("DATA\\admins.dat", "rb");


	int acctmp = 0;
	userlist->accounts_count = 0;
	userlist->phead = NULL;

	if (file != NULL)
	{
		fread(&acctmp, sizeof(int), 1, file);

		decrypt_number_4(&(acctmp));

		Logindata tmp;
		for (int i = 0; i < acctmp; i++)
		{
			fread(&tmp, sizeof(Logindata), 1, file);
			decrypt_logindata(&tmp);
			addnewadmin(userlist, tmp);
		}
		fclose(file);
	}
}


void admindatasave(Admin_list *userlist)
{
	_mkdir("DATA");
	FILE *file = fopen("DATA\\admins.dat", "wb");

	int acctmp = userlist->accounts_count;
	encrypt_number_4(&acctmp);
	fwrite(&acctmp, sizeof(int), 1, file);

	Admin *tmpp = userlist->phead;
	Logindata tmplogin;
	while (tmpp)
	{
		tmplogin = tmpp->logindata;
		encrypt_logindata(&tmplogin);
		fwrite(&tmplogin, sizeof(Logindata), 1, file);
		tmpp = tmpp->next;

	}
	fclose(file);

}


void hs_savehistory(TransfersHis *list, char *login)
{
	_mkdir("DATA");

	char filename[LOGIN_L + 5 + 4];
	strcpy(filename, "DATA\\");
	strcat(filename, login);
	strcat(filename, ".his");

	FILE *file = fopen(filename, "wb");

	if (file != NULL)
	{
		int count = list->transferscount;

		encrypt_number_4(&count);
		fwrite(&count, sizeof(int), 1, file);

		Onetransfer *tmp = list->phead;
		Transferdata datatmp;

		while (tmp)
		{
			datatmp = tmp->transferdata;
			encrypt_tranferdata(&datatmp);
			fwrite(&datatmp, sizeof(Transferdata), 1, file);
			tmp = tmp->pnext;
		}
		fclose(file);
	}
}


void hs_loadhistory(TransfersHis *list, char *login)
{
	//DATA\<LOGIN>.his
	char filename[LOGIN_L + 5 + 4];
	strcpy(filename, "DATA\\");
	strcat(filename, login);
	strcat(filename, ".his");

	FILE *file = fopen(filename, "rb");
	list->phead = NULL;
	list->ptail = NULL;
	list->transferscount = 0;

	int count = 0;

	if (file != NULL)
	{
		fread(&count, sizeof(int), 1, file);
		decrypt_number_4(&count);
		Transferdata data;

		for (int i = 0; i < count; i++)
		{
			fread(&data, sizeof(Transferdata), 1, file);
			decrypt_tranferdata(&data);
			hs_addtransfer(list, data);
		}

		fclose(file);
	}

}