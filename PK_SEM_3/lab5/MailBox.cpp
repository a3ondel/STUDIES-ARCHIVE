#include "MailBox.h"
#include "User.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <string>

MailBox::MailBox(const string& name_of_logfile, const string& name_of_backupfile)
{
	this->log.open(name_of_logfile,std::fstream::app);
	int i = -1;
	std::ifstream file(name_of_backupfile);
	std::string tmp = "";
	
	if (file)
	{
		
		while (std::getline(file,tmp))
		{
			if (tmp.find("\1\1\1") < std::string::npos)
			{
				i++;
				continue;
			}

			
			mbox[i] += tmp;
			mbox[i] += "\n";
		}

		file.close();
	}
	
}

MailBox::~MailBox()
{
	std::ofstream file;
	file.open("backup.txt");

	if (file)
	{
		for (int i = 0; i < 10; i++)
		{
			file << "\1\1\1" << "\n";  //oznaczenie kolejnego usera
			file << mbox[i] << "\n";
			
			mbox[i] = "";
		}
		file.close();
	}
	this->log.close(); //otwarte w konstruktorze
	
}

bool MailBox::send(const string& msg, User* sender, User* reciever)
{
	if (reciever == sender)
		return false;
	
	//this->log.open("log.txt", std::fstream::app);
	//otwarte

	time_t rawtime;
	time(&rawtime);
	std::string tmp = "";
	if (log) 
	{
		
		if (msg.length() + this->mbox[reciever->myid].length() > std::string::npos)
		{	
			log <<"\n"<< ctime(&rawtime) << "error";
			return false;// przepelniona skrzynka
		}

		log << "\n";
		tmp += "czas nadania: ";
		tmp += ctime(&rawtime);
		tmp += "id odbiorcy: ";
		tmp += std::to_string(reciever->myid);
		tmp += ", nazwa odbiorcy: ";
		tmp += reciever->nickname;
		tmp += ", id nadawcy: ";
		tmp+=std::to_string(sender->myid);
		tmp += ", nazwa nadawcy: "; 
		tmp+=sender->nickname;

		log << tmp;
		tmp += "\nTresc: ";
		tmp += msg;
		//tmp += "\n***********\n";
		mbox[reciever->myid]+=tmp;
		mbox[reciever->myid]+= "\n***********\n";
		//mbox[reciever->myid].insert(mbox[reciever->myid].find_first_of("*"),"\n");
		
		
		
	//	log.close();
	}
	
	return false;
}

string MailBox::receive(User* user)
{
	return mbox[user->myid];

}

void MailBox::print()
{
	for (int i = 0; i < N; i++)
	{
		std::cout <<"id "<<i<<":----------------\\/"<<std::endl<< mbox[i];
	}
}
