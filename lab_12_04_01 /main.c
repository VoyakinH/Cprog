#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int main()
{
    char mode[4];
    if (read_mode(FILE_NAME, mode) != OK || check_mode(mode) != OK)
        return READ_MODE_ERR;
    return OK;
}
