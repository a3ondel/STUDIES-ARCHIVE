#ifndef READ_H
#define READ_H


#include "structures.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utility.h"

int read_file(char *filename, BMP *img);
int read_filehead(FILE *file, FILEHEADER *head);
int read_imghead(FILE *file, IMGHEADER *head);
	

void read_array( FILE *file, BMP *img);


#endif 