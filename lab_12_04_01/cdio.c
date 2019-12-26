#include <stdio.h>
#include <ctype.h>
#include "defines.h"

int read_mode(FILE *f, char mode[])
{
    if (fgets(mode, 5, f) == NULL)
        return READ_MODE_ERR;
    if (mode[3] != '\n')
        return READ_MODE_ERR;
    mode[3] = '\0';
    return OK;
}

int read_int(FILE *f, int *val)
{
    if (fscanf(f, "%d", val) != 1 || *val < 1)
        return READ_INT_ERR;
    char buff = fgetc(f);
    if (buff != '\n' && buff != ' ')
        return READ_INT_ERR;
    return OK;
}
