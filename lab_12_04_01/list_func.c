#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int init_list(list **factors)
{
    list *factors_new = calloc(1, sizeof(list));
    if (!factors)
        return ALLOCATION_ERR;
    *factors = factors_new;
    (*factors)->pow = 0;
    (*factors)->factor = 2;
    (*factors)->next_factor = NULL;
    return OK;
}

int increase_list(list **factors)
{
    list *factors_new = calloc(1, sizeof(list));
    if (!factors_new)
        return ALLOCATION_ERR;
    factors_new->next_factor = *factors;
    factors_new->factor = (*factors)->factor + 1;
    factors_new->pow = 0;
    *factors = factors_new;
    return OK;
}

void free_list(list **factors)
{
    while ((*factors) && (*factors)->next_factor != NULL)
    {
        list *buff = *factors;
        *factors = (*factors)->next_factor;
        free(buff);
    }
    free(*factors);
    return;
}

void output_list(FILE *f, list *factors)
{
    while (factors != NULL)
    {
        fprintf(f, "%d %d ", factors->factor, factors->pow);
        list *buff = factors;
        factors = factors->next_factor;
        free(buff);
    }
    printf("1\n");
    return;
}

void combine_lists(list **factors_both, list **factors)
{
    list *backup = *factors_both;
    list *buff = NULL;
    while (*factors != NULL)
    {
        if ((*factors_both) == NULL)
        {
            (*factors_both) = (*factors);
            backup = (*factors);
            (*factors) = (*factors)->next_factor;
            (*factors_both)->next_factor = NULL;
        }
        else if ((*factors_both)->factor == (*factors)->factor)
        {
            (*factors_both)->pow += (*factors)->pow;
            list *buff_to_free = (*factors);
            (*factors) = (*factors)->next_factor;
            free(buff_to_free);
        }
        else if ((*factors)->factor > (*factors_both)->factor)
        {
            buff = (*factors);
            (*factors) = (*factors)->next_factor;
            buff->next_factor = (*factors_both);
            (*factors_both) = buff;
            backup = (*factors_both);
        }
        else if ((*factors_both)->next_factor == NULL)
        {
            (*factors_both)->next_factor = (*factors);
            ((*factors_both)->next_factor)->next_factor = NULL;
            (*factors) = (*factors)->next_factor;
        }
        else if ((*factors)->factor < (*factors_both)->factor)
        {
            (*factors_both) = (*factors_both)->next_factor;
        }
    }
    (*factors_both) = backup;
    return;
}
