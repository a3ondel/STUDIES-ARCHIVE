#pragma once
inline void LINIA() { std::cout << "------" << std::endl; };

template <typename T>
class Lista
{
	struct element
	{
		T zawartosc;
		element* pnext;

		element(T zawartosc_) :zawartosc(zawartosc_), pnext(nullptr) {};
	};

	element* phead;
	element* tail;

public:

	Lista() :phead(nullptr), tail(nullptr) {}

	void delete_list()
	{
		while (phead)
		{
			auto tmp = phead->pnext;
			delete phead;
			phead = tmp;
		}
		phead = nullptr;
		tail = nullptr;
	}

	void dodaj(T dana)
	{
		if (!phead)
		{
			phead = new element(dana);
			tail = phead;
		}
		else
		{
			tail->pnext = new element(dana);
			tail = tail->pnext;
		}
	};

	void wypisz()
	{
		if (phead)
		{
			auto tmp = phead;
			while (tmp)
			{
				std::cout << tmp->zawartosc << std::endl;
				tmp = tmp->pnext;
			}
		}
		else
			std::cout << "Lista jest pusta" << std::endl;
		LINIA();
	};

	~Lista() { delete_list(); }
};

class Punkt
{
public:
	int x;
	int y;
	Punkt() :x(0), y(0) {};
	Punkt(const int& x_, const int& y_) :x(x_), y(y_) {};
};

template <>
class Lista<Punkt>
{
	struct element
	{
		Punkt zawartosc;
		element* pnext;

		element(Punkt zawartosc_) :zawartosc(zawartosc_), pnext(nullptr) { };//dodalem konstruktor
	};

	element* phead;
	element* tail;//dodany ogon do dodawania na koniec listy

public:

	Lista() :phead(nullptr), tail(nullptr) {}

	void delete_list()
	{
		while (phead)
		{
			auto tmp = phead->pnext;
			delete phead;
			phead = tmp;
		}

		phead = nullptr;
		tail = nullptr;
	}

	void dodaj(Punkt dana)
	{
		if (!phead)
		{
			phead = new element(dana);
			tail = phead;
		}
		else
		{
			tail->pnext = new element(dana);
			tail = tail->pnext;
		}
	};

	void wypisz()
	{
		if (phead)
		{
			auto tmp = phead;
			while (tmp)
			{
				std::cout << "x: " << tmp->zawartosc.x << " y:" << tmp->zawartosc.y << std::endl;
				tmp = tmp->pnext;
			}
		}
		else
			std::cout << "Lista jest pusta" << std::endl;

		LINIA();
	}

	~Lista() { delete_list(); }
};

template <typename T1, typename T2>
class Schowek
{
public:
	T1 x;
	T2 y;
	Schowek(const T1& x_, const T2& y_) :x(x_), y(y_) {};

	void pokaz()
	{
		std::cout << "Zawartosc schowka:" << std::endl;
		std::cout << "wartosc 1: " << x << "\nwartosc 2: " << y << std::endl;
		LINIA();
	}
};