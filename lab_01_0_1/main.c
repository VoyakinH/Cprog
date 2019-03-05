#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, h;
	scanf("%f%f%f", &a, &b, &h);
if (a == 0 || b == 0 || h == 0)
{
	a = 0;
	b = 0;
	h = 0;
}
	h = sqrt(((fabs(a - b) / 2) * (fabs(a - b) / 2)) + (h * h));
	h = h + h + a + b;
    printf("%.5f", h);
    return 0;
}
