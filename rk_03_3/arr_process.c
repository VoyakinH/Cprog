#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void rotate_arr(mat *array, mat *new_array)
{
	for (int k = 0; k < new_array->m; k++)
	{
		int count = k;
		for (int i = 0; i < array->n - k; i++)
		{
			new_array->arr[count][k] = array->arr[i][k];
			count++;
		}

		for (int i = k + 1; i < array->n; i++)
		{
			new_array->arr[count][k] = array->arr[array->n - k - 1][i];
			count++;
		}
	}
	return;
}

