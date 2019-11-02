#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	int n, m;
	if (scanf("%d %d", &n, &m) != 2)
		return -1;

	mat *array = malloc(sizeof(mat));
	if (!array)
		return -2;

	if (init_arr(&array, n, m) != 0)
	{
		free(array);
		return -3;
	}

	if (read_arr(array, n, m) != 0)
	{
		free_arr(array, n);
		free(array);
		return -4;
	}

	int t_n = n + m - 1;
	int t_m = count_diag(n, m);

	mat *t_array = malloc(sizeof(mat));
	init_triangle_arr(&t_array, t_n, t_m);
	rotate_arr(array, t_array, n, m, t_n, t_m);
	free_arr(array, n);


	out_arr(t_array, t_n, t_m);
	free_arr(t_array, t_n);
	free(array);
}
