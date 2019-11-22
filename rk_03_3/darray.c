#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int init_arr(mat **array)
{
	(*array)->arr = calloc((*array)->n, sizeof(int*));
    if (!(*array)->arr)
        return ALLOCATION_ERR;

	for (int i = 0; i < (*array)->n; i++)
    {
        (*array)->arr[i] = calloc((*array)->m, sizeof(int));
        if (!(*array)->arr[i])
            return ALLOCATION_ERR;
    }

	return OK;
}

void free_arr(mat *array)
{
	for (int i = 0; i < array->n; i++)
		free(array->arr[i]);

	free(array->arr);
    free(array);
	return;
}
	
