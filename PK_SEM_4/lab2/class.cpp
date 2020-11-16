#include "class.h"
#include <string>

Patient::Patient(std::string _id)
{
	
	if (_id.length() != 11)
		throw std::length_error("Zla dlugosc id");

	if (_id.find_first_not_of("0123456789") != std::string::npos)
		throw std::invalid_argument("Nieprawidlowy format id");

	id = _id;
}

Quarantine::Quarantine(const std::string& _msg):msg(_msg){}

const char* Quarantine::what() const noexcept
{
	return msg.c_str();
}

HospitalLimit::HospitalLimit(const std::string& _msg):msg(_msg){}

const char* HospitalLimit::what() const noexcept
{
	return msg.c_str();
}

bool Hospital::isExists(std::string id)
{

	for (auto pat : patients)
	{
		if (pat->id == id)
			return true;
		
		
	}
	return false;
}
void Hospital::Add(std::string id)
{
	if (iterator == limit)
		throw HospitalLimit("Nie ma miesjca w szpitalu");

	Patient* newpat=nullptr;
	try
	{
		newpat = new Patient(id);
	}
	catch (const std::exception& ob)
	{
		delete newpat;
		throw;
	}

	if (isExists(id))
		throw std::string("Pacjent jest juz w szpitalu");

	patients.push_back(newpat);
	iterator++;
	
	if ((newpat->id[10]) % 3 == 0)
		throw Quarantine("Pacjent ma wirusa SARS");

}
Hospital::Hospital(int lim_):iterator(0),limit(lim_){}

Hospital::~Hospital()
{
	for (auto pat: patients)
	{
		delete pat;
		pat = nullptr;
	}
}

