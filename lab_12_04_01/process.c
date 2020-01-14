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

int int_to_list(FILE *fin, list **factors)
{
    int val = 0;
    if (read_int(fin, &val) != OK)
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

int out_func(FILE *fin, list **factors)
{
    return int_to_list(fin, factors);
}

int sqr_func(FILE *fin, list **factors)
{
    int res = int_to_list(fin, factors);
    if (res != OK)
        return res;
    double_every_pow(*factors);
    return OK;
}

int mul_func(FILE *fin, list **factors)
{
//  -------------------
//      HARD WAY
//  -------------------
    list *factors_2;
    int res = int_to_list(fin, factors);
    if (res != OK)
        return res;
    res = int_to_list(fin, &factors_2);
    if (res != OK)
    {
        free_list(factors);
        return res;
    }
    combine_lists(factors, &factors_2);
//  -------------------
//      EASY WAY
//  -------------------
//    int val_1, val_2;
//    if (read_int(FILE_NAME, &val_1) != OK)
//        return READ_INT_ERR;
//    if (read_int(FILE_NAME, &val_2) != OK)
//        return READ_INT_ERR;
//    val_1 *= val_2;
//    if (init_list(&factors) != OK || factorize(&factors, val_1) != OK)
//        return ALLOCATION_ERR;
//  -------------------
    return OK;
}

int div_func(FILE *fin, list **factors)
{
//  -------------------
//       EASY WAY
//  -------------------
    int val_1, val_2;
    if (read_int(fin, &val_1) != OK || read_int(fin, &val_2) != OK)
        return READ_INT_ERR;
    val_1 /= val_2;
    if (val_1 == 0)
        return READ_INT_ERR;
    if (init_list(factors) != OK || factorize(factors, val_1) != OK)
        return ALLOCATION_ERR;
    if ((*factors)->pow == 0)
    {
        free(*factors);
        *factors = NULL;
    }
//  -------------------
    return OK;
}

int check_mode(const char mode[])
{
    if (strcmp(mode, "out") == 0)
        return OUT_FUNC;
    else if (strcmp(mode, "mul") == 0)
        return MUL_FUNC;
    else if (strcmp(mode, "div") == 0)
        return DIV_FUNC;
    else if (strcmp(mode, "sqr") == 0)
        return SQR_FUNC;
    return READ_MODE_ERR;
}
