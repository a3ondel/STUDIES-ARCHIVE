#include <stdio.h>
#include "structures.h"
#include "statefunctions.h"
#include "drinkstates.h"
#include "settingsandrefill.h"


int main()
{
	state_func_t * const state_table[NUMBER_OF_STATES] = { do_state_error,do_state_initial ,do_state_wait_4_user,do_state_exit ,do_state_error,
	do_small_coffe ,do_big_coffe ,do_espresso, do_cappucino ,do_hotmilk ,set_coffe_power ,set_base_water,refill_coffe,refill_water,refill_milk };


	state_t current_state = ST_INITIAL;
	coffe_machine machine1;
	


	while (current_state != ST_OFF)
	{
		current_state = run_state(current_state, &machine1,state_table);
	}


	return 0;
}