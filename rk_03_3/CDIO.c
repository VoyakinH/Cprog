#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int read_size(FILE *f, mat *array)
{
    int n;
    if (fscanf(f, "%d", &n) != 1 || n < 1)
        return READ_SIZE_ERR;

    array->n = n;
    array->m = n;
    return OK;
}

int read_arr(FILE *f, mat *array)
{
    for (int i = 0; i < array->n; i++)
        for (int j = 0; j < array->m; j++)
            if (fscanf(f, "%d", &array->arr[i][j]) != 1)
                return READ_ARR_ERR;

    return OK;
}

void out_arr(FILE *f, mat *array)
{
    fprintf(f, "\n");
    for (int i = 0; i < array->n; i++)
    {
        for (int j = 0; j < array->m; j++)
            fprintf(f, "%d ", array->arr[i][j]);
        fprintf(f, "\n");
    }
    return;
}
