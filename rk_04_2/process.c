#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "define.h"
#include "func.h"

int read_str(char name[256])
{
	char elem;
	int n = 0;
	elem = getc(stdin);
	while (elem != '\n' && n < 256)
	{
		name[n] = elem;
		elem = getc(stdin);
		n++;
	}
	return n - 1;;
}

int read_cities(list **cities)
{
	char name[256];
	char region[256];
	char fed_okr[256];
	int nas;
	int year;
	read_str(name);
	while (strcmp(name, "end") != 0)
	{
		read_str(region);
		read_str(fed_okr);
		scanf("%d", &nas);
		scanf("%d", &year);
		copy_to_list(cities, name, region, fed_okr, nas, year);
		create_next(cities);
		read_str(name);
	}
}