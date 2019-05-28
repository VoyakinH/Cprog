#include <stdio.h>
#define N 100

int input_size(int *n, int *m)
{
	int rs = scanf("%d%d", &*n, &*m);
	if (rs != 2 || rs == EOF || *n < 1 || *m < 1)
		return -1;
	
	return 0;
}

int input_arr(int arr[][N], int n, int m)
{
	int rs;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			rs = scanf("%d", &arr[i][j]);
			if (rs != 1 || rs == EOF)
				return -1;
		}
	return 0;
}

void get_index_max(int arr[][N], int n, int m, int *ind_max)
{
	*ind_max = 0;
	int value_max = arr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] > value_max)
			{
				value_max = arr[i][j];
				*ind_max = j;
			}
	return;
}

void get_index_min(int arr[][N], int n, int m, int *ind_min)
{	
	*ind_min = 0;
	int value_min = arr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] < value_min)
			{
				value_min = arr[i][j];
				*ind_min = j;
			}
	return;
}

void switch_row(int arr[][N], int n, int m, int ind_max, int ind_min)
{
	int buff;
	for(int i = 0; i < n; i++)
	{
		buff = arr[i][ind_max];
		arr[i][ind_max] = arr[i][ind_min];
		arr[i][ind_min] = buff;
	}
	return;
}

void print_arr(int arr[][N], int n, int m)
{
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return;
}

int main()
{
	int n, m, ind_max, ind_min;
	if (input_size(&n, &m) != 0)
		return 1;
	int arr[N][N];
	if (input_arr(arr, n, m) != 0)
		return 2;
	get_index_max(arr, n, m, &ind_max);
	get_index_min(arr, n, m, &ind_min);
	if (ind_min != ind_max)
		switch_row(arr, n, m, ind_max, ind_min);
	print_arr(arr, n, m);
	return 0;
}
