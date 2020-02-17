#pragma once
#include <string>
#include <fstream>
using std::string;
using std::ofstream;

const int N = 10;
class User;

class MailBox
{
	std::string mbox[N]; //tablica wiadomo�ci od  uzytkownikow skrzynki // indeksem tablicy jest id uzytkownika
					
	std::ofstream log; //plik z raportem

	std::ofstream backup; // zawarto�� mbox do pliku backup gdy usuwamy obiekt
	
public:

	MailBox(const string& name_of_logfile, const string& name_of_backupfile); // je�eli plik backup  ju� istnieje wczytuje go do mbox
	
	~MailBox(); // zapisuje wszystkie wiadomo�ci do backup i usuwa z pami�ci

	
	std::string receive(User* user); // zwraca " " w przypadku b��du - indeks poza zakresem, lub gdy nie ma wiadomo�ci dla tego u�ytkownika
	bool send(const string& msg, User* sender, User* reciever);// uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
	

	void print(); // wy�ietla wszystkie wiadomo�ci w skrzynce

	friend class User; 
};

