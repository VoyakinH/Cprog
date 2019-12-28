#include <stdio.h>
#include <stdlib.h>
#include "libdynarr.h"

int read_array(int n, double **a)
{
    double *new_a = malloc(sizeof(double) * n);
    if (new_a)
    {
        *a = new_a;
        new_a = NULL;
    }
    else
    {
        free(*a);
        return READ_ARR_ERR;
    }
    for (int i = 0; i < n; i++)
        if (scanf("%lf", *a + i) != 1)
            return READ_ARR_ERR;
    return OK;
}

int new_size(double **a, int n)
{
    double *new_a = realloc(*a, sizeof(double) * (n + 3));
    if (new_a)
    {
        *a = new_a;
        new_a = NULL;
    }
    else
    {
        free(a);
        return MEM_ERR;
    }
    return OK;
}
