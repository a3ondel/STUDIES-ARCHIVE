#pragma once
#include <string>


template<typename T>
auto dodaj(T x, T y)
{
	return x + y;
}

template <>
auto dodaj(char a, char b)
{
	std::string tmp = "";
	tmp += a;
	tmp += b;
	return tmp;
}









