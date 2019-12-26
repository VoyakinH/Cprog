#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int main()
{
    char mode[5];
    if (read_mode(FILE_NAME, mode) != OK)
        return READ_MODE_ERR;
    return check_mode(mode);
}
