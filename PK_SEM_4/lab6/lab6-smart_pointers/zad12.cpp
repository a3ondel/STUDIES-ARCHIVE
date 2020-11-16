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
		//Stw�rz trzy unique_pointery. Pierwszy o typie <Person>, drugi o typie <Woman>, a trzeci o typie <Man>.
		std::unique_ptr<Person> pP(new Person);
		std::unique_ptr<Man> pM = std::make_unique<Man>();
		std::unique_ptr<Woman> pW(new Woman());
		std::cout << std::endl;
		
		//spr�buj wywo�a� metod� printMe() i zaobserwuj co si� stanie
		
		pP->printMe();
		pM->printMe();
		pW->printMe();
		std::cout << std::endl;
		
		//przepnij smart pointer typu Woman na typ Person u�ywaj�c metody move(), a nast�pnie wywo�aj metod� printMe()
		
		pP = std::move(pW);
		pP->printMe();
		std::cout << std::endl;
		
		//stw�rz dwa wska�niki typu <Man> i sprawd� ich adresy wypisuj�c je na standardowe wyj�cie,
		//a nast�pnie przepnij je metod� move() i ponownie sprawd� ich adresy w pami�ci
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
		//zdefiniuj tablic� liczb ca�kowitych o rozmiarze 5 u�ywaj�c std::unique_ptr<int[]>
		
		std::unique_ptr<int[]> parray(new int [5]);
		std::cout << std::endl;
		//metod� std::unique_ptr::get() wypisz na standardowe wyj�cie adres kom�rek tablicy
		for (int i = 0; i < 5; i++)
			std::cout << parray.get()+i << std::endl;
		
		std::cout << std::endl;
		
		//nast�pnie zape�nij tablic� losowymi warto�ciami z przedzia�u od 0 do 100
		for (int i = 0; i < 5; i++)
			parray[i] = rand()%101;
		std::cout << std::endl;
		
		//za pomoc� metody std::unique_ptr::get() wypisz zawarto�� tablicy oddzielaj�c ka�d� liczb� znakiem "_"
		for (int i = 0; i < 5; i++)
			std::cout << *(parray.get() + i) << "_";

		std::cout << std::endl;
	}
	return 0;
}
#endif
