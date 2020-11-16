#if 0 //aktywowanie jednego z pilu cpp z mainem
#include <iostream>
#include <memory>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include  <ctime>

class Person
{
private:
	std::string name;
	std::string surname;
public:
	Person(std::string _name = "No name", std::string _surname = "No surname") : name(_name), surname(_surname)
	{
		std::cout << "Person constructed." << std::endl;
	}
	~Person()
	{
		std::cout << "Person destroyed." << std::endl;
	}
	virtual void printMe()
	{
		std::cout << "Person class here !!" << std::endl;
	}
	void printName()
	{
		std::cout << name << std::endl;
	}
};
class Woman : public Person
{
public:
	Woman(std::string _name = "No name", std::string _surname = "No surname") : Person(_name, _surname)
	{
		std::cout << "Woman constructed." << std::endl;
	}
	~Woman()
	{
		std::cout << "Woman destructed." << std::endl;
	}
	void printMe()
	{
		std::cout << "Woman class here !!" << std::endl;
	}
};
class Man : public Person
{
public:
	Man(std::string _name = "No name", std::string _surname = "No surname") : Person(_name, _surname)
	{
		std::cout << "Man constructed." << std::endl;
	}
	~Man()
	{
		std::cout << "Man destructed." << std::endl;
	}
	void printMe()
	{
		std::cout << "Man class here !!" << std::endl;
	}
};

class SHP
{
public:
	SHP()
	{
		std::cout << "SHP contructor here!" << std::endl;
	}
	~SHP()
	{
		std::cout << "DESTRUCTOR of SHP class" << std::endl;
	}
};

int main()
{
	
	{
		//zadanie1
		//Stwórz trzy unique_pointery. Pierwszy o typie <Person>, drugi o typie <Woman>, a trzeci o typie <Man>.
		std::unique_ptr<Person> pP(new Person);
		std::unique_ptr<Man> pM = std::make_unique<Man>();
		std::unique_ptr<Woman> pW(new Woman());
		std::cout << std::endl;
		
		//spróbuj wywo³aæ metodê printMe() i zaobserwuj co siê stanie
		
		pP->printMe();
		pM->printMe();
		pW->printMe();
		std::cout << std::endl;
		
		//przepnij smart pointer typu Woman na typ Person u¿ywaj¹c metody move(), a nastêpnie wywo³aj metodê printMe()
		
		pP = std::move(pW);
		pP->printMe();
		std::cout << std::endl;
		
		//stwórz dwa wskaŸniki typu <Man> i sprawdŸ ich adresy wypisuj¹c je na standardowe wyjœcie,
		//a nastêpnie przepnij je metod¹ move() i ponownie sprawdŸ ich adresy w pamiêci
		std::unique_ptr<Man>M1(new Man());
		std::unique_ptr<Man>M2(new Man);
		std::cout << std::endl;
		
		std::cout << M1<<std::endl;
		std::cout << M2 << std::endl;
		std::cout << std::endl;

		M1 = std::move(M2);
		std::cout << std::endl;
		
		std::cout << M1 << std::endl;
		std::cout << M2 << std::endl;
		std::cout << std::endl;
	}

	
	{
		srand(time(NULL));
		//zadanie2
		//zdefiniuj tablicê liczb ca³kowitych o rozmiarze 5 u¿ywaj¹c std::unique_ptr<int[]>
		
		std::unique_ptr<int[]> parray(new int [5]);
		std::cout << std::endl;
		//metod¹ std::unique_ptr::get() wypisz na standardowe wyjœcie adres komórek tablicy
		for (int i = 0; i < 5; i++)
			std::cout << parray.get()+i << std::endl;
		
		std::cout << std::endl;
		
		//nastêpnie zape³nij tablicê losowymi wartoœciami z przedzia³u od 0 do 100
		for (int i = 0; i < 5; i++)
			parray[i] = rand()%101;
		std::cout << std::endl;
		
		//za pomoc¹ metody std::unique_ptr::get() wypisz zawartoœæ tablicy oddzielaj¹c ka¿d¹ liczbê znakiem "_"
		for (int i = 0; i < 5; i++)
			std::cout << *(parray.get() + i) << "_";

		std::cout << std::endl;
	}
	return 0;
}
#endif
