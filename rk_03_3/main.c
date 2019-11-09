#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int main()
{
	mat *array = malloc(sizeof(mat));
	if (!array)
		return ALLOCATION_ERR;

    if (read_size(stdin, array) != OK)
    {
        free(array);
        return READ_SIZE_ERR;
    }

	if (init_arr(&array) != OK)
	{
        free_arr(array);
		return ALLOCATION_ERR;
	}

	if (read_arr(stdin, array) != OK)
	{
		free_arr(array);
		return READ_ARR_ERR;
	}

	mat *new_array = malloc(sizeof(mat));
    if (!array)
    {
        free_arr(array);
        return ALLOCATION_ERR;
    }

    new_array->n = 2 * array->n - 1;
    new_array->m = array->n;

	if (init_arr(&new_array) != OK)
    {
        free_arr(array);
        free_arr(new_array);
        return ALLOCATION_ERR;
    }

	rotate_arr(array, new_array);
    out_arr(stdout, new_array);

    free_arr(array);
	free_arr(new_array);
    return OK;
}
