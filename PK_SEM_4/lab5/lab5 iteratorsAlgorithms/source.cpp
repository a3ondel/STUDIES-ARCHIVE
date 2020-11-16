#include  <iostream>
#include  <list>
#include  <vector>
#include  <deque>
#include  <algorithm>
#include  <iterator>

bool con_check(int number)
{

	return sqrt(number) == (int)sqrt(number);
}

class Triple
{
	int a;
	int b;
	int c;
	
public:
	
	Triple(int a_, int b_, int c_) :a(a_),b(b_),c(c_){};

	
	bool operator==(const Triple &tr)
	{

		return (a == tr.a && b == tr.b && c == tr.c);
	}
	
	friend std::ostream& operator<<(std::ostream& output, const Triple& tr) {
		
		return output << tr.a << " " << tr.b << " " << tr.c << std::endl;
	}

};


int main()
{
	std::cout << Triple(1, 1, 1);
	//zad 1
	std::list<char>lista = { 'a','b','c','d','e','x' };
	
	auto iteratorkon = lista.rbegin();

	for (auto i = lista.begin();i!=lista.end();i++)
	{
		std::cout << *i<<" ";
	}
	std::cout << std::endl;

	for (auto i = lista.rbegin(); i != lista.rend(); i++)
	{
		std::cout << *i<<" ";
	}

	//zad 2

	std::vector<int> v = { 1,2,32,71,12,45,26,36,80,53,33,64 };

	//a)
	std::sort(v.begin(), v.end());

	//b)
	std::sort(v.rbegin(), v.rend());

	//c)
	std::sort(v.begin(), v.end(), [](int e_1, int e_2)
	{
			if ((con_check(e_1) && con_check(e_2)) || (!con_check(e_1) && !con_check(e_2)))	
				return e_1 > e_2;

		return con_check(e_1); 
		
	});

	//d)
	std::sort(v.begin(), v.begin(), [](int e_1, int e_2) {return e_1 % 5 < e_2 % 5; });
	
	//zad 3
	std::deque<Triple> TripleDeq;
	std::front_insert_iterator<std::deque<Triple>> Deq_start(TripleDeq);

	for (int ai=1;ai<50;ai++)
	{
		for (int bi=1;bi<50;bi++)
		{
			for (int ci=1;ci<50;ci++)
			{
				if (ai * ai + bi * bi == ci * ci)
					*Deq_start = Triple(ai, bi, ci);
				
			}	
		}
	}

	//dodanie po dwa elementy na pocz i na koniec
	*std::front_insert_iterator<std::deque<Triple>>(TripleDeq) = Triple(-5, -5, -5);
	*std::front_insert_iterator<std::deque<Triple>>(TripleDeq) = Triple(-55, -55, -55);
	*std::back_insert_iterator<std::deque<Triple>>(TripleDeq) = Triple(99, 99, 99);
	*std::back_insert_iterator<std::deque<Triple>>(TripleDeq) = Triple(999, 999, 999);

	//wstawianie na 10 pozycje (indeks=9)
	*std::insert_iterator<std::deque<Triple>>(TripleDeq,TripleDeq.begin()+9)=Triple(666,666,666);

	//sprawdzenie pod jakim indeksem znajduje sie trojka 3,4,5
	std::cout << "index: "<<std::find(TripleDeq.begin(), TripleDeq.end(), Triple(3, 4, 5))-TripleDeq.begin();

	//wypisanie wszystkich trojek w deque
	for (const auto &i : TripleDeq)
		std::cout << i<<std::endl;

	
	return 0;
}