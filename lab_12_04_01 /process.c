#include <stdio.h>
#include <string.h>
#include "defines.h"
#include "func.h"

int factorize(stack **factors, int val)
{
    while (val != 1)
    {
        while (val % (*factors)->factor == 0)
        {
            val /= (*factors)->factor;
            ((*factors)->pow)++;
        }
        if (val != 1)
        {
            if (increase_stack(factors) != OK)
            {
                free_stack(factors);
                return ALLOCATION_ERR;
            }
        }
    }
    return OK;
}

int out_func(void)
{
    int val;
    if (read_int(FILE_NAME, &val) != OK)
        return READ_INT_ERR;
    stack *factors;
    if (init_list(&factors) != OK)
        return ALLOCATION_ERR;
    if (factorize(&factors, val) != OK)
    {
        free_stack(&factors);
        return ALLOCATION_ERR;
    }
    output_stack(stdout, factors);
    return OK;
}

int check_mode(const char mode[])
{
    if (strcmp(mode, "out") == 0)
        out_func();
//    else if (strcmp(mode, "mul") == 0)
//
//    else if (strcmp(mode, "div") == 0)
//
//    else if (strcmp(mode, "sqr") == 0)
//
    else
        return READ_MODE_ERR;
    return OK;
}
