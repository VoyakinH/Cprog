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

    int mode_int = check_mode(mode);
    int result = OK;
    switch (mode_int)
    {
        case OUT_FUNC:
            result = out_func(stdin, &factors);
            break;
        case MUL_FUNC:
            result = mul_func(stdin, &factors);
            break;
        case DIV_FUNC:
            result = div_func(stdin, &factors);
            break;
        case SQR_FUNC:
            result = sqr_func(stdin, &factors);
            break;
        default:
            return READ_MODE_ERR;
    }

    if (result == OK)
        output_list(stdout, factors);
    return result;
}
