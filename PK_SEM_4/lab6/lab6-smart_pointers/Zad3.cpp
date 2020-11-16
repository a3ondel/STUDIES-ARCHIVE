#if 1
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>

class towar {
	unsigned int ilosc;
public:
	towar(unsigned int _ilosc) : ilosc(_ilosc) {
		std::cout << "towar::towar(_ilosc)" << std::endl;
	}
	~towar() {
		std::cout << "towar::~towar()" << std::endl;
	}

	unsigned int getIlosc() 
	{
		return ilosc;
	}

	bool pobierz(unsigned int ilosc_)
	{
		if (ilosc_ > this->ilosc)
			return false;
		else
			this->ilosc -= ilosc_;
		
		return true;
	}
};

class sklep {
	unsigned int zuzycie;
	std::vector<std::shared_ptr<towar>> towary;

public:
	sklep(unsigned int _zuzycie) : zuzycie(_zuzycie) {
		std::cout << "sklep::sklep(_zuzycie)" << std::endl;
	}
	~sklep() {
		std::cout << "sklep::~sklep()" << std::endl;
	}

	void dodajTowar(std::shared_ptr<towar> t1_) 
	{
		towary.push_back(t1_);
	}

	void zuzyjTowar() 
	{
		for(int i=0;i<towary.size();i++)
		{

			if(towary[i]->pobierz(zuzycie))
			{
				if (towary[i]->getIlosc() == 0)
				{
					std::cout << "Towar o adresie " << towary[i] << " zostal uzyty w calosci" << std::endl;
					towary.erase(towary.begin() + i);
					i--;
				}
				else
					std::cout << "zuzyto towar o adresie: " << towary[i] << std::endl;
			}
			else
			{
				std::cout << "brak odpowiedniej ilosci towaru o adresie: " << towary[i] << std::endl;
				towary.erase(towary.begin()+i);
				i--;
			}
		}	
	}
};

int main()
{
	/* Zadanie 3 Uzupe�nij klasy i dopisz logike w main():
		Sklep - klasa zu�ywaj�ca pewn� sta�� ilo�� towaru dla wszystkich towar�w. Klasa sklep zawiera:
			1. ilo�� towaru jak� zu�ywa sklep (sta�a dodatnia liczba)
			2. wektor towar�w dost�pnych w sklepie
			3. metod� dodaj�c� towary do sklepu (wektora)
			4. metod� zu�ywaj�c� towary
		Towar - klasa b�d�ca odzwierciedleniem towaru dost�pnego w magazynie. Klasa Towar zawiera:
			1. ilo�� dost�pnego towaru
			2. metod� zwracaj�c� ilo�� dost�pnego towaru
			3. metod� zmniejszaj�c� ilo�� dost�pnego towaru o zu�ycie danego sklepu

		Sprawdzaj podczas dzia�ania programu jak zmieniaj� si� liczniki referencji,
		oraz usuwaj z wektor�w te towary, kt�re si� zu�y�y, b�d� gdy dany sklep nie mo�e
		ich pobra� z tak ma�ej puli.
	*/

	/* Przyk�adowe stworzenie sklep�w i towar�w i ich przypisanie */

	sklep pierwszy(1);
	sklep drugi(5);
	sklep trzeci(2);
	std::vector<std::shared_ptr<towar>> towary;

	for (const int& ilosc : { 5, 7, 11, 6, 13, 9 })
	{
		towary.push_back(std::make_shared<towar>(ilosc));
	}
	
	pierwszy.dodajTowar(towary[0]);
	pierwszy.dodajTowar(towary[1]);
	pierwszy.dodajTowar(towary[2]);
	pierwszy.dodajTowar(towary[3]);
	pierwszy.dodajTowar(towary[4]);
	pierwszy.dodajTowar(towary[5]);
	
	drugi.dodajTowar(towary[0]);
	drugi.dodajTowar(towary[1]);
	drugi.dodajTowar(towary[2]);
	drugi.dodajTowar(towary[4]);
	
	trzeci.dodajTowar(towary[2]);
	trzeci.dodajTowar(towary[3]);
	trzeci.dodajTowar(towary[4]);

	while (towary.size() > 0)
	{
		pierwszy.zuzyjTowar();
		drugi.zuzyjTowar();
		trzeci.zuzyjTowar();

		for (int i=0;i<towary.size();i++)
		{
			//jezeli pusto to usuwanie z z vectora towary 
			 if(!towary[i]->getIlosc())
			{
				std::cout << "Towar o adresie: " << towary[i] << " ma " << towary[i].use_count()-1 << " odwolan " << std::endl;
				towary.erase(towary.begin() + i);
				i--;
			}
			else
				std::cout << "Towar o adresie: " << towary[i] << " ma " << towary[i].use_count() << " odwolan " << std::endl;
		}
	}

	return 0;
}
#endif
