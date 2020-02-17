#include "drinkstates.h"
#include <stdio.h>
#include "utility.h"
#include "print.h"


state_t do_small_coffe(coffe_machine *data)
{
	data->previous_state = ST_SMALLCOFEE;

	if (data->coffe_amount < data->coffe_power) //sprawdzanie czy jest wystarczajaca ilosc kawy
		return REFIL_COFFE;
	if (data->water_amount < data->base_size)//sprawdzanie czy jest wystarczajaca ilosc wody
		return REFIL_WATER;
	
	pintsmall(); //wypisywanie informacji i chwilowa przerwa

	data->coffe_amount = data->coffe_amount - data->coffe_power;//sprawdzanie czy jest wystarczajaca ilosc kawy
	data->water_amount = data->water_amount - data->base_size; //sprawdzanie czy jest wystarczajaca ilosc wody

	return ST_WAIT_4_USER;
}

state_t do_big_coffe(coffe_machine * data)
{
	data->previous_state = ST_BIGCOFFE;

	if (data->coffe_amount < data->coffe_power  *3) //sprawdzanie czy jest wystarczajaca ilosc kawy
		return REFIL_COFFE;
	if (data->water_amount < data->base_size    *3) //sprawdzanie czy jest wystarczajaca ilosc wody
		return REFIL_WATER;

	printbig(); //wypisywanie informacji i chwilowa przerwa
	
	data->coffe_amount = data->coffe_amount - data->coffe_power  *3; //aktualizacja informacji na temat ilosci kawy
	data->water_amount = data->water_amount - data->base_size    *3; // aktualizacja informacji na temat ilosci wody

	return ST_WAIT_4_USER;
}

state_t do_espresso(coffe_machine * data)
{
	
	data->previous_state = ST_ESPRESSO;

	if (data->coffe_amount < data->coffe_power) //sprawdzanie czy jest wystarczajaca ilosc kawy
		return REFIL_COFFE;
	if (data->water_amount < data->base_size /5) //sprawdzanie czy jest wystarczajaca ilosc wody
		return REFIL_WATER;

	printespr(); //wypisywanie informacji i chwilowa przerwa

	data->coffe_amount = data->coffe_amount - data->coffe_power; //aktualizacja informacji na temat ilosci kawy
	data->water_amount = data->water_amount -  data->base_size /5; // aktualizacja informacji na temat ilosci wody

	return ST_WAIT_4_USER;
}


state_t do_cappucino(coffe_machine * data)
{
	data->previous_state =ST_CAPPUCINO;

	if (data->coffe_amount < data->coffe_power *2) //sprawdzanie czy jest wystarczajaca ilosc kawy
		return REFIL_COFFE;
	if (data->water_amount < data->base_size   *2) //sprawdzanie czy jest wystarczajaca ilosc wody
		return REFIL_WATER;
	if (data->milk_amount < data->base_size   / 2) //sprawdzanie czy jest wystarczajaca ilosc mleka
		return REFIL_MILK;

	printcapp(); //wypisywanie informacji i chwilowa przerwa

	data->coffe_amount = data->coffe_amount - data->coffe_power *2; //aktualizacja informacji na temat ilosci kawy
	data->water_amount = data->water_amount - data->base_size   *2;  // aktualizacja informacji na temat ilosci wody
	data->milk_amount = data->milk_amount - data->base_size     /2;   // aktualizacja informacji na temat ilosci mleka

	return ST_WAIT_4_USER;
}

state_t do_hotmilk(coffe_machine * data)
{
	data->previous_state = ST_HOTMILK;

	if (data->milk_amount < data->base_size)//sprawdzanie czy jest wystarczajaca ilosc mleka
		return REFIL_MILK;

	printmilk(); //wypisywanie informacji i chwilowa przerwa

	data->milk_amount = data->milk_amount - data->base_size;  // aktualizacja informacji na temat ilosci mleka

	return ST_WAIT_4_USER;
}
