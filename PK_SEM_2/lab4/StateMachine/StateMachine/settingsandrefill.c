#include "settingsandrefill.h"
#include <stdio.h>
#include "utility.h"
#include <conio.h>

state_t set_coffe_power(coffe_machine *data)
{
	char tmp;
	cls();
	printf_s("Wybierz moc kawy:\n");
	printf_s("1.slaba\n");
	printf_s("2.normalna\n");
	printf_s("3.mocna\n");
	do
	{
		tmp = _getch();
	} while (tmp<'1' || tmp>'3'); //pobieranie odpowiedniego klawisza

	switch (tmp)
	{
	case '1':
		data->coffe_power = 1; // mnoznik ilosci kawy slabej
		break;
	case '2':
		data->coffe_power = 2; // mnoznik ilosci kawy normalnej
		break;
	case '3':
		data->coffe_power = 3; // mnoznik ilosci kawy mocnej
		break;
	}

	return ST_WAIT_4_USER;
}

state_t set_base_water(coffe_machine *data)
{
	char tmp;
	cls();
	printf_s("Wybierz bazowa ilosc wody:\n");
	printf_s("1.150ml\n");
	printf_s("2.200ml\n");
	printf_s("3.250ml\n");

	do
	{
		tmp = _getch();
	} while (tmp<'1' || tmp>'3');

	switch (tmp)
	{
	case '1':
		data->base_size = 150; //ilosc w ml
		break;
	case '2':
		data->base_size = 200; // ilosc w ml
		break;
	case '3':
		data->base_size = 250; //ilosc w ml
		break;
	}

	return ST_WAIT_4_USER;

}

state_t refill_water(coffe_machine * data)
{
	cls();
	printf_s("Uzupelaninie wody\n");
	printf_s("Nacisnij dowolny przycisk aby przerwac\n");

	int i = data->water_amount;
	for (i; i < 2500; i++) //uzupelnianie do maksymalnej ilosci wody ml
	{
		data->water_amount++;
		if (_kbhit()) //jezeli klawisz wcisniety, uzupelnianie zostaje przerwane
		{
			_getch();//czysczenie bufora wejscia

			printf_s("Przerwano uzupelnianie");
			Sleep(1000);
			return ST_WAIT_4_USER;
		}

		Sleep(1);
	}

	cls();
	printf_s("Woda zostala uzupelniona");
	Sleep(1000);

	return data->previous_state; //powrot do poprzedniego stanu
}

state_t refill_coffe(coffe_machine * data)
{
	cls();
	printf_s("Uzupelaninie kawy\n");
	printf_s("Nacisnij dowolny przycisk aby przerwac\n");

	int i = data->coffe_amount;
	for (i; i <100 ; i++) //uzupelnianie do max w gramach
	{
		data->coffe_amount++;

		if (_kbhit())
		{
			_getch(); //czysczenie bufora wejscia

			printf_s("Przerwano uzupelnianie");
			Sleep(1000);
			return ST_WAIT_4_USER;
		}

			Sleep(20);
	}
	
	cls();
	printf_s("Kawa zostala uzupelniona");
	Sleep(1000);

	return data->previous_state; //powrot do poprzedniego stanu
}

state_t refill_milk(coffe_machine * data)
{
	cls();
	printf_s("Uzupelaninie mleka\n");
	printf_s("Nacisnij dowolny przycisk aby przerwac\n");

	int i = data->milk_amount;
	for (i; i < 1000; i++) //uzupelnienie do max w ml
	{
		data->milk_amount++; 

		if (_kbhit()) //jezeli klawisz zostanie wcisniety 
		{
			_getch();//czysczenie bufora wejscia

			printf_s("Przerwano uzupelnianie");
			Sleep(1000);
			return ST_WAIT_4_USER;
		}

		Sleep(5);
	}
	
	cls();
	printf_s("Mleko zostalo uzupelnione");
	Sleep(1000);

	return data->previous_state; //powrot do poprzedniego stanu
}

