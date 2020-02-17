#pragma once
#include "MailBox.h"
#include<string>
class User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze b�d�ca id nast�pnego  u�ytkownika
	int myid; // id u�ytkownika

	string nickname; // nazwa u�ytkownika
	MailBox* mb;// adres skrzynki z kt�r� jest zwiazany u�ytkownik

public:

	User(MailBox* mb_, const string& nickname_);

	bool send(const string& msg, User& reciever);
	
	bool receive(); // pobieram wiadomo�� ze skrzynki

	friend class MailBox;
};

