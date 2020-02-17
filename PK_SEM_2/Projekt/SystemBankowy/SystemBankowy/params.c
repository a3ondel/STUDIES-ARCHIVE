#include "params.h"
#include <string.h>


int modechoose(int n_elements, char *arg[])
{

	if (n_elements == 1)
		return 0; //usermode
	
	for (int i = 1; i < n_elements; i++)
	{
		if (strcmp(arg[i], "-a") == 0)
			return 1;//adminmode
	}
	
	return 0;//usermode
	

}