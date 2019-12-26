#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int main()
{
    char mode[5];
    list *factors;
    if (read_mode(stdin, mode) != OK)
        return READ_MODE_ERR;
    int err = check_mode(stdin, mode, &factors);
    if (err != OK)
        return err;
    output_list(stdout, factors);
    return OK;
}
