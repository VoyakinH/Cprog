#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(double u1, double *p1, double *p2)
 {
     if (fabs(u1 - fabs(*p1)) > fabs(u1 - fabs(*p2)))
         return 1;
     return 0;
 }

void del(double *a, int *n, double u1)
{
    double *k1, *k2, *p = a;
    int j;
    if (comp(u1, p, p + 1) == 1)
    {
        k1 = p;
        k2 = p + 1;
    }
    else
    {
        k1 = p + 1;
        k2 = p;
    }
    for (int i = 2; i < *n; i++)
    {
        if (comp(u1, p + i, k2) == 1)
        {
            if (fabs(u1 - fabs(*p + i)) > fabs(u1 - fabs(*k1)))
                k1 = p + i;
            else
                k2 = p + i;
        }
    }
    p = a;
    j = 0;
    while (p < k1)
    {
        p++;
        j++;
    }
    for (int i = j; i < *n - 1; i++)
    {
        *p = *(p + 1);
        p++;
    }
    *n = *n - 1;
    if (k2 > k1)
        k2--;
    if (k2 > p)
        k2 = p;
    p = a;
    j = 0;
    while (p < k2)
    {
        p++;
        j++;
    }
    for (int i = j; i < *n - 1; i++)
    {
        *p = *(p + 1);
        p++;
    }
    *n = *n - 1;
    return;
}
