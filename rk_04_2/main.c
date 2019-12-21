#include "func.h"
#include "define.h"
#include <stdio.h>

int main()
{
	list *cities;
	list *buff = cities;
	init_list(&cities);
	read_cities(&cities);
	//cities = buff;
	output_list(cities);
	return OK;
}