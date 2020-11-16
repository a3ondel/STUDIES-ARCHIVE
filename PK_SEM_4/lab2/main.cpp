#include <iostream>
#include "class.h"
#include <string>

int main()
{
	Hospital Polsl(5);

	try
	{
		while(1) 
		{
			try
			{

				std::string tmp = "";
				std::getline(std::cin, tmp);
				Polsl.Add(tmp);
			}
			catch (Quarantine & ob)
			{
				std::cout << ob.what();
			}
			catch (std::invalid_argument & ob)
			{
				std::cout << ob.what();

			}
			catch (std::length_error & ob)
			{
				std::cout << ob.what();
			}
			catch (std::string &ob)
			{
				std::cout << ob;
			}
		}
	}
	catch (HospitalLimit &ob)
	{
		std::cout << ob.what();
		return 666;
	}
	catch (...)
	{
		std::cout << "Nieobsluzony wyjatek";
		return 2137;

	}
	return 0;
}