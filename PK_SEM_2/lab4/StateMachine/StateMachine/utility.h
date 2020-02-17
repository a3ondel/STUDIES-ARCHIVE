#pragma once
#include <Windows.h>
#include "structures.h"
#include <stdio.h>

void cls();
void fileload(FILE *File, coffe_machine *data);
void filesave(FILE *File, coffe_machine *data);

