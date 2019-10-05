#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "defines.h"

void find_min(int64_t ***a_p, int n, int m, int *x, int *y)
{
    int i, j;
    *x = n - 1;
    *y = m - 1;
    int64_t min = (*a_p)[n - 1][m - 1];
    for (i = n - 1; i > -1; i--)
        for (j = m - 1; j > -1; j--)
            if ((*a_p)[i][j] < min)
            {
                min = (*a_p)[i][j];
                *x = i;
                *y = j;
            }
    return;
}

void make_square(int64_t ***a_p, int *n, int *m)
{
    int x = 0, y = 0, i, j;
    while (*n != *m)
    {
        find_min(a_p, *n, *m, &x, &y);
        if (*n > *m)
        {
            for (i = 0; i < *m; i++)
                for (j = x; j < *n - 1; j++)
                    (*a_p)[j][i] = (*a_p)[j + 1][i];
            *n = *n - 1;
        }
        else
        {
            for (i = 0; i < *n; i++)
                for (j = y; j < *m - 1; j++)
                    (*a_p)[i][j] = (*a_p)[i][j + 1];
            for (i = (*m - 1) * *n - 2; i >= *m - 1; i = i - *m)
                for (j = i; j < *m * *n - 2; j++)
                    (*a_p)[0][j] = (*a_p)[0][j + 1];
            *m = *m - 1;
        }
    }
    return;
}
