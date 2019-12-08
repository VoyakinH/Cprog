#include <stdio.h>
#include "defines.h"

int read_mode(FILE *f, char mode[])
{
    if (fgets(mode, 4, f) == NULL)
        return READ_MODE_ERR;
    return OK;
}

int read_int(FILE *f, int *val)
{
    if (fscanf(f, "%d", val) != 1 || *val < 1)
        return READ_INT_ERR;
    return OK;
}
