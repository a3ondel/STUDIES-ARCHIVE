#include <iostream>
#include "header.h"
#include <Windows.h>


void color(const int a)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, a);

}