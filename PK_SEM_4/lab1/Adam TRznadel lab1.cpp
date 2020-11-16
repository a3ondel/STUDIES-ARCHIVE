// Adam TRznadel lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


class Car
{
	int iterator;

public:
	virtual ~Car() {};

	static bool canBeParkedUnderGround(Car* car);


	static bool compare(Car* car1, Car* car2);




};

class ElectricCar : public Car
{
public:

	void charge()
	{
		std::cout << "Twoj samochodzik jest ladowany pradem" << std::endl;
	}

};

class LPGCar :public Car
{
public:

	void fuelLpg()
	{
		std::cout << "Gazik za 20zl " << std::endl;
	}

};

class DieselCar :public Car
{
public:
	void fuelDiesel()
	{
		std::cout << "Diesel leci" << std::endl;
	}

};

class TankStelle
{
	std::string getCarType(Car* car)
	{   //0123456
		//class name
		if (car)
			return typeid(*car).name();
		else
			return "";
	}
public:
	void fuel(Car* car)
	{
		if (car)
			switch (getCarType(car)[6])
			{
			case 'L': dynamic_cast<LPGCar*>(car)->fuelLpg();
				break;
			case 'E': dynamic_cast<ElectricCar*>(car)->charge();
				break;
			case 'D': dynamic_cast<DieselCar*>(car)->fuelDiesel();
				break;
			}
	}

};

int main()
{
	for (auto carx : {(Car*)new LPGCar(),(Car*)new DieselCar(),(Car*)new ElectricCar()})
	{
		TankStelle().fuel(carx);
		std::cout << "Mozna parkowac pod ziemia? -" << (Car::canBeParkedUnderGround(carx) ? "tak" : "nie") << std::endl
				  << (std::string) "Czy diesel to " + typeid(*carx).name() + "? - "
				  << (Car::compare(new DieselCar(), carx) ? "tak" : "nie") << std::endl << std::endl;
	}

	return 0;
}

bool Car::canBeParkedUnderGround(Car* car)
{
	return (typeid(*car) != typeid(LPGCar));

}

bool Car::compare(Car* car1, Car* car2)
{
	return (typeid(*car1) == typeid(*car2));
}
