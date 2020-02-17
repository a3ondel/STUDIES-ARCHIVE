#include "User.h"
#include "MailBox.h"
#include <iostream>

int User::id = 0;

User::User(MailBox* mb_, const string& nickname_) :nickname(nickname_), mb(mb_)
{
	if(id<N)
		myid = id++; //przypisanie unikalnego id
}

bool User::send(const string& msg, User& reciever)
{
	
	mb->send(msg, this, &reciever); // wywo�ujemy send w klasie Mbox
	return true;

}

bool User::receive()
{
	if (mb->mbox[this->id] != "")
	{
		std::cout << mb->receive(this); // wywo�ujemy send w klasie Mbox
		mb->mbox[this->myid] = "";				// wy�wietla wiadomo�� na ekranie // nast�pnie usuwa
		return true; // watchout
	}
	else
		return false;
}
