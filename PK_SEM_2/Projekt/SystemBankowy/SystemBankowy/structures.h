#ifndef structures_H
#define structures_H

#define LOGIN_L 11
#define PASSWORD_L 13
#define CITY_L 21
#define STREET_L 21
#define HOUSE_L 10
#define NAME_L 31
#define SURNAME_L 31
#define PESEL_L 12
#define DATE_L 20
#pragma pack(push, 1)

typedef struct logindata_t
{
	char login[11]; //stala dlugosc
	char password[13]; //maksymalna dlugosc hasla 12 znakow
	int login_attemps;	//liczba prob logowania, jezeli wartosc wieksza od 3 brak mozliwosci logowania do konta

}Logindata;

typedef struct Adress_t
{
	char city[21]; //miasto zamieszkania
	char street[21]; // ulica 
	char house_number[10]; //numer domu itp
}Adress;


typedef struct Userdata_t
{
	char name[31]; //dlugos 30 +1 na \0
	char surrname[31]; //dlugos 30 +1 na \0
	char pesel[12]; //dlugos 11 +1 na \0
	
}Userdata;

typedef struct Data_t
{
	Logindata logindata;
	Userdata userdata;
	Adress adress;
	long long int balance;

}Data;

typedef struct dlinkedlist
{
	Data data;
	struct dlinkedlist *previous;
	struct dlinkedlist *next;


}User;

typedef struct Userlist_t
{
	int accounts_count;
	User *phead;


}User_list;

typedef struct admin_t
{
	Logindata logindata;
	struct admin_t *previous;
	struct admin_t *next;


}Admin;

typedef struct admin_list_t
{
	int accounts_count;
	Admin *phead;

}Admin_list;

typedef struct transferdata_t
{
	int type;// RECVIE/SEND
	char name[31];
	char surrname[31];
	Adress adress;
	char date[20];
	long long int transfermoney;
	long long int accountmoney;

}Transferdata;

typedef struct onetransfer_t
{
	Transferdata transferdata;
	struct onetransfer_t *pnext;

}Onetransfer;

typedef struct transfershis_t
{
	int transferscount;
	Onetransfer *phead;
	Onetransfer *ptail;

}TransfersHis;



#pragma pack(pop)

#endif 

