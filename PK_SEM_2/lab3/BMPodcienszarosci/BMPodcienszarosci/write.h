#ifndef WRITE_H_
#define WRITE_H_

#include "structures.h"
#include "utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int write_file(char *filename, BMP *img);
void headerupdate(BMP *imgtmp,int padding);

#endif 
