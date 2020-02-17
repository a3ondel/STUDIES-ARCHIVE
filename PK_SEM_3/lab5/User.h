#pragma once
#include "MailBox.h"
#include<string>
class User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze bêd¹ca id nastêpnego  u¿ytkownika
	int myid; // id u¿ytkownika

	string nickname; // nazwa u¿ytkownika
	MailBox* mb;// adres skrzynki z któr¹ jest zwiazany u¿ytkownik

public:

	User(MailBox* mb_, const string& nickname_);

	bool send(const string& msg, User& reciever);
	
	bool receive(); // pobieram wiadomoœæ ze skrzynki

	friend class MailBox;
};

