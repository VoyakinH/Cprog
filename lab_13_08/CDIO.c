#include <stdio.h>
#include "libdynarr.h"

int read_n(FILE *f, int *n)
{
    if (fscanf(f, "%d", n) == 1 && *n > 2)
        return OK;
    else
        return READ_N_ERR;
}

int read_p(FILE *f, int *p, int n)
{
    if (fscanf(f, "%d", p) == 1 && *p >= 0 && *p < n - 1)
        return OK;
    else
        return READ_P_ERR;
}

void out_arr(double *a, int n)
{
    double *p = a;
    for (int i = 0; i < n; i++)
    {
        printf("%.6lf ", *p);
        p++;
    }
    printf("\n");
    return;
}
