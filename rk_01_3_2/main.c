#include <stdio.h>
#define N 100

int input_n()
{
	int n, rs;
	rs = scanf("%d", &n);
	if (rs != 1 || rs == EOF || n <= 0)
		return -911;
	return n;
}

int input_arr(int array[N], int n)
{
	int rs;
	for (int i = 0; i < n; i++)
	{
		rs = scanf("%d", &array[i]);
		if (rs == EOF || rs != 1 || array[i] < 1)
			return -911;
	}
	return 0;
}

int fact(int x)
{
	int s = 1;
	for (int i = 1; i <= x; i++)
		s *= i;
	return s;
}

int vstavka(int array[N], int n)
{
	int i = 0;
	int j;
	while (i < n)
	{
		n++;
		for (j = n - 1; j > i + 1; j--)
			array[j] = array[j - 1];
		array[i + 1] = fact(array[i]);
		i += 2;
	}
	return n;
}

void output(int array[N], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	return;
}

int main(void)
{
	int n;
	n = input_n();
	if (n == -911)
		return 1;
	int array[N];
	if (input_arr(array, n) == -911)
		return 1;
	n = vstavka(array, n);
	output(array, n);
	return 0;
}