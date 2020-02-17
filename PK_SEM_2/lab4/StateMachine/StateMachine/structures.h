#pragma once

typedef enum { ST_ERROR, ST_INITIAL, ST_WAIT_4_USER, ST_EXIT,ST_OFF,ST_SMALLCOFEE,ST_BIGCOFFE,ST_ESPRESSO,ST_CAPPUCINO,
			 ST_HOTMILK,ST_COFFEPOWERSET,ST_BASEWATERSET,REFIL_COFFE,REFIL_WATER,REFIL_MILK,NUMBER_OF_STATES } state_t;

typedef struct coffe_maker
{
	int coffe_amount;
	int water_amount;
	int milk_amount;
	int coffe_power;
	int base_size; 
	state_t previous_state; //stan do ktorego nalezy powrocic po uzupelnianiu zasobow
}coffe_machine;


typedef state_t state_func_t(coffe_machine * data);



