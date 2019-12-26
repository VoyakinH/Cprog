#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int factorize(list **factors, int val)
{
    while (val > 1)
    {
        while (val % (*factors)->factor == 0)
        {
            val /= (*factors)->factor;
            ((*factors)->pow)++;
        }
        if ((*factors)->pow == 0)
            ((*factors)->factor)++;
        else if (val != 1)
        {
            if (increase_list(factors) != OK)
            {
                free_list(factors);
                return ALLOCATION_ERR;
            }
        }
    }
    return OK;
}

int int_to_list(list **factors)
{
    int val = 0;
    if (read_int(FILE_NAME, &val) != OK)
        return READ_INT_ERR;
    if (init_list(factors) != OK)
        return ALLOCATION_ERR;
    if (factorize(factors, val) != OK)
    {
        free_list(factors);
        return ALLOCATION_ERR;
    }
    if ((*factors)->pow == 0)
    {
        free(*factors);
        *factors = NULL;
    }
    return OK;
}

void double_every_pow(list *factors)
{
    list *buffer = factors;
    while (buffer != NULL)
    {
        buffer->pow *= 2;
        buffer = buffer->next_factor;
    }
    return;
}

int out_func()
{
    list *factors;
    int res = int_to_list(&factors);
    if (res != OK)
        return res;
    output_list(stdout, factors);
    return OK;
}

int sqr_func()
{
    list *factors;
    int res = int_to_list(&factors);
    if (res != OK)
        return res;
    double_every_pow(factors);
    output_list(stdout, factors);
    return OK;
}

int mul_func()
{
//  -------------------
//      HARD WAY
//  -------------------
    list *factors_1;
    list *factors_2;
    int res = int_to_list(&factors_1);
    if (res != OK)
        return res;
    res = int_to_list(&factors_2);
    if (res != OK)
        return res;
    combine_lists(&factors_1, &factors_2);
    output_list(stdout, factors_1);
//  -------------------
//      EASY WAY
//  -------------------
//    list *factors = NULL;
//    int val_1, val_2;
//    if (read_int(FILE_NAME, &val_1) != OK)
//        return READ_INT_ERR;
//    if (read_int(FILE_NAME, &val_2) != OK)
//        return READ_INT_ERR;
//    val_1 *= val_2;
//    if (init_list(&factors) != OK || factorize(&factors, val_1) != OK)
//        return ALLOCATION_ERR;
//    output_list(stdout, factors);
//  -------------------
    return OK;
}

int div_func()
{
//  -------------------
//       EASY WAY
//  -------------------
    list *factors = NULL;
    int val_1, val_2;
    if (read_int(FILE_NAME, &val_1) != OK || read_int(FILE_NAME, &val_2) != OK)
        return READ_INT_ERR;
    val_1 /= val_2;
    if (val_1 == 0)
        return READ_INT_ERR;
    if (init_list(&factors) != OK || factorize(&factors, val_1) != OK)
        return ALLOCATION_ERR;
    if (factors->pow == 0)
    {
        free(factors);
        factors = NULL;
    }
    output_list(stdout, factors);
//  -------------------
    return OK;
}

int check_mode(const char mode[])
{
    if (strcmp(mode, "out") == 0)
        return out_func();
    else if (strcmp(mode, "mul") == 0)
        return mul_func();
    else if (strcmp(mode, "div") == 0)
        return div_func();
    else if (strcmp(mode, "sqr") == 0)
        return sqr_func();
    return READ_MODE_ERR;
}
