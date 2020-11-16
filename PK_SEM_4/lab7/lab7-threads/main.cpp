/*
ZADANIE 1
Utworzyæ dwa w¹tki, pierwszy za pomoc¹ wskaŸnika na funkcjê, drugi za pomoc¹ obiektu funkcyjnego.
Ich zadaniem jest inkrementowanie zmiennej iterator.
W¹tki maj¹ wykonaæ siê po kolei.


ZADANIE 2
Stworzyæ funkcje digit_checker() ktora sprawdzi, czy u¿ytkownik poda³ liczbê.
Je¿eli input nie bêdzie liczb¹, wyrzuciæ odpowiedni wyj¹tek a nastêpnie z³apaæ
go w funkcji main, wyœwietlaj¹c w konsoli komunikat o b³êdzie. W funkcji main
stworzyæ w¹tek który wykona tê funkcjê. Pamiêtaæ o zadeklarowaniu std::exception_ptr
i zsynchronizowaniu w¹tku z g³ównym.


ZADANIE 3
Zaimplementowaæ obliczanie liczb pierwszych z dowolnego przedzia³u za pomoc¹ wektora
w¹tków o dowolnej wielkoœci dziel¹c po równo przedzia³ na ka¿dy w¹tek
(np je¿eli w¹tki s¹ 4, a liczby z zakresu [1, 100000], niech pierwszy sprawdza liczby z zakresu [1, 25000]).
Nale¿y pamiêtaæ o ochronie wspó³dzielonych danych.
*/
#include <algorithm>
#include<thread>
#include<iostream>
#include<exception>
#include<stdexcept>
#include<fstream>
#include <functional>
#include<mutex>
#include<vector>
#include<time.h>

void Zad1ThreadFun(int &i)
{
    i++;
    std::cout << "Watek Funkcja\n";
}

class Zad1Thread
{
public:
	void operator()(int &i)
	{
        i++;
        std::cout << "Watek Obiek funkcyjny\n";
	}
	
    Zad1Thread() = default;
};

//zad2
//------------------------------

void digit_checker(std::exception_ptr &pException)
{
    try
    {
        int a=0;
        std::cout << "Podaj liczbe" << std::endl;
    	
        if (!(std::cin >> a))
        {
            std::cin.sync();
            std::cin.clear();
            throw std::exception("To nie liczba");
        }
    }
    catch (...)
    {
        pException = std::current_exception();
    }
}
//zad3
//---------------------------------------------------------

std::vector<int> pn_main;
std::vector<int> pn_multi_t;
std::mutex blocker;

//--------------------------------------\/MOJE----------------------------
inline bool isPrime(int &x)
{
    for (int y = 2; y <= sqrt(x); y++)
    {
        if ((x % y) == 0)
        {
            return false;
        }
        else if ((y + 1) == x)
        {
            return true;
        }
    }
}
const int lcore = std::thread::hardware_concurrency();
const int lcore_p1 = lcore + 1;

void number_assign(int thred_number,int total) {

    if (!(thred_number % 2))
        thred_number += lcore_p1;
	
    for (int i = thred_number; i < total; i += 2*lcore) 
    {
    	if (isPrime(i)) 
        {
            blocker.lock();
            pn_multi_t.push_back(i);
            blocker.unlock();
        }
    }
}

void FindPrime(int start, int end, unsigned int threadNum)
{
    std::vector<std::thread> fred_vector;
	
    for (int i = 0; i < threadNum; i++) 
        fred_vector.emplace_back(number_assign, i, end);
     
    for (auto& e : fred_vector)
		  e.join();
	
}

int main()
{
     int iterator = 0;

//ZADANIE 1
    Zad1Thread fun_thread;
    std::thread t1(fun_thread, std::ref(iterator));
    t1.join();
    std::thread t2(Zad1ThreadFun, std::ref(iterator));
    t2.join();

    std::cout << iterator << std::endl;

//ZADANIE 2
     
        std::exception_ptr pException = nullptr;
        std::thread zad2_t(digit_checker, std::ref(pException));
        zad2_t.join();

        if (pException)
            try
        {
            std::rethrow_exception(pException);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    
//ZADANIE 3
    constexpr auto range = 0xfffffff; //~420s 16 rdzeni logicznych
    int endTime = 0, startTime = 0;

	startTime = clock();
	pn_main.push_back(2);
    /*for (int x = 1; x <= range; x += 2) 
        if (isPrime(x)) 
           pn_main.push_back(x); *///zakomentowane z powodu dlugie czasu wykonywania 
    endTime = clock();
	
    std::cout << "Normal execution time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << " s" << std::endl;

	//
    startTime = clock();
    FindPrime(1, range, std::thread::hardware_concurrency());
    endTime = clock();
	
    pn_multi_t.erase(pn_multi_t.begin());
	
    std::cout << "Execution time with threads : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << " s" << std::endl;
  
    return 0;
}