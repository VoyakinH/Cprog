#include "define.h"
#include "func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_list(list **cities)
{
	*cities = malloc(sizeof(list));
	(*cities)->next = NULL;
}

void copy_to_list(list **cities, char name[], char region[], char fed_okr[], int nas, int year)
{
	(*cities)->gorod_info = malloc(sizeof(gorod));
	(*cities)->gorod_info->name = malloc(sizeof(char) * (strlen(name) + 1));
	(*cities)->gorod_info->region = malloc(sizeof(char) * (strlen(region) + 1));
	(*cities)->gorod_info->fed_okr = malloc(sizeof(char) * (strlen(fed_okr) + 1));
	strcpy((*cities)->gorod_info->name, name);
	strcpy((*cities)->gorod_info->region, region);
	strcpy((*cities)->gorod_info->fed_okr, fed_okr);
	(*cities)->gorod_info->nas = nas;
	(*cities)->gorod_info->year = year;
}

void create_next(list **cities)
{
	list *buff = malloc(sizeof(list));
	(*cities)->next = buff;
	buff->next = NULL;
	*cities = buff;
	return;
}

void output_list(list *cities)
{
	while (cities && cities->next != NULL)
	{
		printf("%s\n%s\n%s\n%d\n%d\n", cities->gorod_info->name, cities->gorod_info->region, cities->gorod_info->fed_okr, cities->gorod_info->nas, cities->gorod_info->year);
		cities = cities->next;
	}
	//printf("%s\n%s\n%s\n%d\n%d\n", cities->gorod_info->name, cities->gorod_info->region, cities->gorod_info->fed_okr, cities->gorod_info->nas, cities->gorod_info->year);
}