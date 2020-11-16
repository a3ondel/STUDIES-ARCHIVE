//#include "pch.h"
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>	
#include <exception>

 /*
Zadanie 1  // NOLINT(clang-diagnostic-comment)

 Wypisz poni�ej wyra�enia reguralne do znajdowania:
 W ka�dym podpunkcie w nawiasie znajduje si� zdanie kt�rego mo�na u�y� do sprawdzenia czy wymy�lone wyra�enie dzia�a
a) S�owa "world" ("Hello world")

 ODP:
	"world"

-----------------------------
 b) Wszystkich liczb podzielnych przez 2 ("2 13 22  22222 156 44 800 33333323 ")

ODP:
 	"\d*[02468]" mozna dodac \b na koniec jezeli nie chcemy wiciagac liczb z jakichkolwiek stringow

-----------------------------

 c) Wszystkich �miech�w w zdaniu:
 ("x")
 S� 4 rodzaje, powtarzaj�ce si� ha lub Ha, powtarzaj�ce si� hue, powtarzaj�ce si� he, powtarzaj�ce si� ho zako�czone xd z nieokre�lon� ilo�ci� d

ODP:
	"(([Hh]a)+|(hue)+|(he)+|(ho)+xd+)"
	

-----------------------------
 d) Ci�gu "\\", jednego lub wi�cej '+', ci�gu zaczynaj�cego si� znakiem '*' i jednego lub wi�cej '+',
 ci�gu "{2,}" powtarzajacego sie 2 lub wiecej razy  
 ("\\ ++++++++++++ *++ {2,}{2,} {2,}{2,}{2,}")

ODP:
	(\\\\|\++|\*\++|(\{2,\}){2,})

-----------------------------

 e) Sprawdzi czy ciag zawiera przynajmniej jedna du�� liter�, jedn� ma�a liter�, jedn� cyfr�, jeden znak specjalny np.'!' 
 ("aA1!" "AAAASDASDZDascz123141!!!" "!!312AAczx") Tutaj musimy zdania testowa� osobno.

ODP:
 (?=.[a-z])(?=.[A-Z])(?=.[0-9])(?=.[!@#\$\%\^]).*$

-----------------------------
f)
 Wypisz wszystkie ciagi znakow, kt�re s� poprawne wed�ug poni�szego wyra�enia
 ((1|2)(tak|nie)\2)\1

ODP:
	1tak11tak1
	1nie11nie1
	2tak22tak2
	2nie22nie2

*/



//----------------------------ZAD 2----------------------------------------------------------
														

class User
{
public:
	std::string email;
	std::string password;
	User(std::string _email, std::string _password)
	{
		if (std::regex_match(_email, std::regex("(\w|\.)*\@(gmail\.com|(student\.polsl|onet)\.pl)")))
			email = _email;
		else
			throw std::exception("wrong email");

		if (std::regex_match(_password, std::regex(".{8,}")))
		{
			if (!std::regex_search(_password, std::regex("(01234567|7654321|abcdefgi|12345678|87654321)")))
			{

				if (!std::regex_match(_password, std::regex(".*(.)\\1\\1.*")))
					password = _password;
				else
					throw std::exception("Characters are reapeting to much!");
			}
			else
				throw std::exception("Password is to easy, dont use combinations like 01234567!");	
		}
		else
			throw std::exception("password is to short");
		
	};
};



//----------------------------ZAD 3----------------------------------------------------------													

namespace fs = std::filesystem; // uwaga, jezeli nie dzia�a to czytaj podpowiedzi pod zadaniem 3

// getIndex - funkcja przyjmuje linijk� z prawid�owego pliku i zwraca numer fragmentu klucza
int getIndex(std::string s) {
	int num = 0;
	s.erase(s.find(" "), s.length() - 1);
	return std::stoi(s);
}

// getKeyFragment - funkcja przyjmuje linijk� z prawid�owego pliku i zwraca tre�� fragmentu klucza
std::string getKeyFragment(std::string s) {
	s.erase(0, s.find(" ") + 1);
	return s;
}

void zad3()
{
//-------a
	std::regex reg("^[!@#$%^&*()_+=-`~]{2}2[0-9][A-Za-z]+[+#@].*_[^!@{}_]{2,5}@\\\W+(#|o)?.*$");
	std::vector<std::string> mysteriousPassword;
	std::string fileName = "";
	std::string path = "text_files/";

//--------bc
	for (const auto& entry : fs::directory_iterator(path)) 
	{
		fileName = entry.path().u8string();
		fileName.erase(fileName.end() - 4, fileName.end());

		if(fileName.size()>=11)
			fileName.erase(fileName.begin(),fileName.begin()+11);
			
		if (std::regex_match(fileName, reg)) 
		{
			std::ifstream inputFile(entry.path());
			std::string tmp = "";
			std::getline(inputFile, tmp);
			mysteriousPassword.push_back(tmp);
			inputFile.close();
		}
	}

//---------d
	std::sort(mysteriousPassword.begin(), mysteriousPassword.end(),
		[](const std::string& a, const std::string& b) -> bool {return getIndex(a) < getIndex(b);});

	std::cout << std::endl << std::endl << "Mysterious password: ";

	for (auto s : mysteriousPassword) 
		std::cout << getKeyFragment(s);
}

int main()
{
	//Zadanie pierwsze w komentarzach u gory
	
	//Zadanie 2
	try {
		User user("imie_nazwisko@gmail.com", "0123jjj56789");
	}
	catch (std::exception &e){ std::cout << e.what()<< std::endl; }

	//Zadanie 3	
	zad3();
	
	return 0;
}

