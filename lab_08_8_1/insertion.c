#include <stdio.h>
#include <stdlib.h>

void insert(double *a, int *n, int p, double u2)
{
    a = (double*)realloc(a, *n + 3);
    double *f = a + p;
    double *end = a;
    for (int i = 0; i < *n; i++)
        end++;
    double *end_1 = end;
    while (end_1 > f)
    {
        *end_1 = *(end_1 - 1);
        end_1 --;
    }
    *f = u2;
    end++;
    end_1 = end;
    while (end_1 > a)
    {
        *end_1 = *(end_1 - 1);
        end_1--;
    }
    *a = u2;
    *(end + 1) = u2;
    *n = *n + 3;
    return;
}
