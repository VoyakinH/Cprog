#include <stdio.h>

int input()
{
	int x, rs;
	rs = scanf("%d", &x);
	if (rs == EOF || rs != 1 || x < 1)
		return -911;
	return x;
}

int summ(int x)
{
	int mi, ma;
	mi = x % 10;
	ma = x % 10;
	x /= 10;
	while (x > 0)
	{
		if (x % 10 < mi)
			mi = x % 10;
		if (x % 10 > ma)
			ma = x % 10;
		x /= 10;
	}
	return ma + mi;
}

void output(int x)
{
	printf("%d", x);
	return;
}

int main(void)
{
	int x = input();
	if (x == -911)
		return 1;
	x = summ(x);
	output(x);
	return 0;
}

	