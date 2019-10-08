#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include "defines.h"
#include "func.h"

void sr_geom(int64_t ***a_p, int n, int i, int64_t *x)
{
    int j = 0;
    double s = 1;
    double power = 1.0 / ((float) n);
    for (j = 0; j < n; j++)
        s *= (double) (*a_p)[j][i];
    *x = (int64_t) floor(pow(fabs(s), power));
    return;
}

int64_t min(int64_t ***a_p, int m, int i)
{
    int64_t x = (*a_p)[i][0];
    for (int j = 1; j < m; j++)
        if (x > (*a_p)[i][j])
            x = (*a_p)[i][j];
    return x;
}

int increase_row_number(int64_t **a, int64_t ***a_p, int *n, int m, int p)
{
    int i = 0;
    int64_t x = 0;
    while (*n != p)
    {
        *n = *n + 1;
        if (new_size(a, a_p, *n, m) != OK)
            return MEM_ERR;
        for (i = 0; i < m; i++)
        {
            sr_geom(a_p, *n - 1, i, &x);
            (*a_p)[*n - 1][i] = x;
        }
    }
    return OK;
}

int increase_col_number(int64_t **a, int64_t ***a_p, int n, int *m, int q)
{
    int i = 0, j = 0;
    while (*m != q)
    {
        *m = *m + 1;
        if (new_size(a, a_p, n, *m) != OK)
            return MEM_ERR;
        for (i = 1; i < n; i++)
            for (j = n * *m - 2; j >= *m * i; j--)
                (*a)[j] = (*a)[j - 1];
        for (i = 0; i < n; i++)
            (*a_p)[i][*m - 1] = min(a_p, *m - 1, i);
    }
    return OK;
}
