#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int init_arr(mat **array, int n, int m)
{
	(*array)->arr = calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		(*array)->arr[i] = calloc(m, sizeof(int));
	return 0;
}

int read_arr(mat *array, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (scanf("%d", &array->arr[i][j]) != 1)
				return -1;
	return 0;
}

void out_arr(mat *array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= array->arr[i][0]; j++)
			printf("%d ", array->arr[i][j]);
		printf("\n");
	}
	return;
}

void free_arr(mat *array, int n)
{
	for (int i = 0; i < n; i++)
		free(array->arr[i]);
	free(array->arr);
	return;
}
	
int count_diag(int n, int m)
{
	if (n < m)
		return n;
	return m;
}

int init_triangle_arr(mat **array, int n, int m)
{
	(*array)->arr = calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		if (i < m)
		{
			(*array)->arr[i] = calloc(i + 2, sizeof(int));
			(*array)->arr[i][0] = i + 1;
		}
		else if (i == m && n % 2 == 0)
		{
			(*array)->arr[i] = calloc(i, sizeof(int));
			(*array)->arr[i][0] = i;
		}
		else if (n % 2 == 0)
		{
			(*array)->arr[i] = calloc(2 * m - i, sizeof(int));
			(*array)->arr[i][0] = 2 * m - i;
		}
		else 
		{
			(*array)->arr[i] = calloc(2 * m - i - 1, sizeof(int));
			(*array)->arr[i][0] = 2 * m - i - 1;
		}
	}	
	return 0;
}

int rotate_arr(mat *array, mat *t_array, int n, int m, int t_n, int t_m)
{
	for (int k = 0; k < t_m; k++)
	{
		int count = k;
		for (int i = m - 1; i >= k; i--)
		{
			t_array->arr[count][k + 1] = array->arr[k][i];
			count++;
		}
		for (int i = k + 1; i < n; i++)
		{
			t_array->arr[count][k + 1] = array->arr[i][k];
			count++;
		}
	}
	return 0;
}
	
	
	