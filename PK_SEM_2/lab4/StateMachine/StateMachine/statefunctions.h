#pragma once
#include "structures.h"


state_t run_state(state_t curr_state, coffe_machine *data, state_func_t **const state_table);
state_t do_state_error(coffe_machine *data);
state_t do_state_initial(coffe_machine *data);
state_t do_state_wait_4_user(coffe_machine *data);
state_t do_state_exit(coffe_machine *data);
