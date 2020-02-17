#include "crypto.h"
#define KEY1 61895035478537962
#define KEY2 18239614914675321
#define KEY3 123
#define KEY4 31
#define KEY5 123556563
#define KEY6 867823479

void encrypt_number(long long int *number)
{
	
	*number = ((*number)^KEY1)+KEY2;

	
}


void encrypt_number_4(int *number)
{
	*number = ((*number) ^ KEY5) + KEY6;

}


void decrypt_number(long long int *number)
{

	*number = ((*number-KEY2)^KEY1) ;

}


void decrypt_number_4(int *number)
{

	*number = ((*number - KEY6) ^ KEY5);

}


void encrypt_string(char *string,int lenght)
{
	
	for(int i=0;i<lenght;i++)
	{
	string[i] = (string[i]^KEY3)+i*KEY4;
		
	}

}


void decrypt_string(char * string,int lenght)
{

	for(int i=0;i<lenght;i++)
	{
		string[i] = (string[i]-i*KEY4) ^ KEY3 ;
		
	}

}


void encrypt_data(Data * data)
{
	encrypt_string(data->adress.city, CITY_L);
	encrypt_string(data->adress.street, STREET_L);
	encrypt_string(data->adress.house_number, HOUSE_L);
	
	encrypt_string(data->userdata.name, NAME_L);
	encrypt_string(data->userdata.surrname, SURNAME_L);
	encrypt_string(data->userdata.pesel, PESEL_L);

	encrypt_string(data->logindata.login,LOGIN_L);
	encrypt_string(data->logindata.password,PASSWORD_L);
	encrypt_number_4(&data->logindata.login_attemps);
	encrypt_number(&data->balance);

}

void encrypt_logindata(Logindata *data)
{
	encrypt_string(data->login, LOGIN_L);
	encrypt_string(data->password, PASSWORD_L);

}

void encrypt_tranferdata(Transferdata *data)
{
	encrypt_number_4(&data->type);
	encrypt_number(&data->transfermoney);
	encrypt_number(&data->accountmoney);

	encrypt_string(data->name,NAME_L);
	encrypt_string(data->surrname,SURNAME_L);
	encrypt_string(data->date,SURNAME_L);
	encrypt_string(data->date,DATE_L);

	encrypt_string(data->adress.city, CITY_L);
	encrypt_string(data->adress.street, STREET_L);
	encrypt_string(data->adress.house_number, HOUSE_L);

}

void decrypt_tranferdata(Transferdata *data)
{
	decrypt_number_4(&data->type);

	decrypt_string(data->name, NAME_L);
	decrypt_string(data->surrname, SURNAME_L);
	decrypt_string(data->date, SURNAME_L);
	decrypt_string(data->date, DATE_L);

	decrypt_string(data->adress.city, CITY_L);
	decrypt_string(data->adress.street, STREET_L);
	decrypt_string(data->adress.house_number, HOUSE_L);
	
	decrypt_number(&data->transfermoney);
	decrypt_number(&data->accountmoney);
	
	
}

void decrypt_data(Data * data)
{
	decrypt_string(data->adress.city, CITY_L);
	decrypt_string(data->adress.street, STREET_L);
	decrypt_string(data->adress.house_number, HOUSE_L);

	decrypt_string(data->userdata.name, NAME_L);
	decrypt_string(data->userdata.surrname, SURNAME_L);
	decrypt_string(data->userdata.pesel, PESEL_L);


	decrypt_string(data->logindata.login, LOGIN_L);
	decrypt_string(data->logindata.password, PASSWORD_L);
	decrypt_number_4(&data->logindata.login_attemps);
	decrypt_number(&data->balance);
}

void decrypt_logindata(Logindata *data)
{
	decrypt_string(data->login, LOGIN_L);
	decrypt_string(data->password, PASSWORD_L);
}





