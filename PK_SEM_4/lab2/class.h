#pragma once
#include <iostream>
#include <vector>
#include <exception>

class Quarantine : public std::exception //done 
{
	std::string msg;
public:
	Quarantine(const std::string& _msg);
	virtual const char* what() const noexcept;
	virtual ~Quarantine() noexcept = default;
};

//------------------------------------------------

class HospitalLimit : public std::exception //done
{
	std::string msg;
public:
	HospitalLimit(const std::string& _msg);
	virtual const char* what() const noexcept;
	virtual ~HospitalLimit() noexcept = default;
};

//-------------------------------------------------

class Patient //done 
{
	std::string id;
	Patient() = delete;
	Patient(std::string _id);
	
	friend class Hospital;
};

//--------------------------------------------------

class Hospital //done
{
	unsigned short iterator;
	unsigned short limit;
	std::vector<Patient*> patients;

	 bool isExists(std::string id);

public:
	void Add(std::string id);
	Hospital(int);
	~Hospital();
};
