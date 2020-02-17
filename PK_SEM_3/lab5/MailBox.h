#pragma once
#include <string>
#include <fstream>
using std::string;
using std::ofstream;

const int N = 10;
class User;

class MailBox
{
	std::string mbox[N]; //tablica wiadomoœci od  uzytkownikow skrzynki // indeksem tablicy jest id uzytkownika
					
	std::ofstream log; //plik z raportem

	std::ofstream backup; // zawartoœæ mbox do pliku backup gdy usuwamy obiekt
	
public:

	MailBox(const string& name_of_logfile, const string& name_of_backupfile); // je¿eli plik backup  ju¿ istnieje wczytuje go do mbox
	
	~MailBox(); // zapisuje wszystkie wiadomoœci do backup i usuwa z pamiêci

	
	std::string receive(User* user); // zwraca " " w przypadku b³êdu - indeks poza zakresem, lub gdy nie ma wiadomoœci dla tego u¿ytkownika
	bool send(const string& msg, User* sender, User* reciever);// uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
	

	void print(); // wyœietla wszystkie wiadomoœci w skrzynce

	friend class User; 
};

