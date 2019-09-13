#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

double* read_array(int n, int* rc)
{
    double *a = malloc(sizeof(double) * n);
    double *p = a;
    if (!a)
    {
        *rc = MEM_ERR;
        return a;
    }
    for (int i = 0; i < n; i++)
    {
        if (scanf("%lf", p) != 1)
        {
            *rc = READ_ARR_ERR;
            break;
        }
        p++;
    }
    return a;
}
