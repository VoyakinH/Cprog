#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void count_u1(double *a, int n, double *u1)
{
    double *p = a;
    int s = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        j = pow(i + 1, 2);
        s += j;
        *u1 += *p * j;;
        p++;
    }
    *u1 /= s;
    return;
}

void count_u2(double *a, int n, double *u2)
{
    double *p = a;
    *u2 = 0;
    for (int i = 0; i < n; i++)
    {
        *u2 += *p / n;
        p++;
    }
    return;
}
