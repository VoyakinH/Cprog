#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int init_list(stack **factors)
{
    stack *factors_new = calloc(1, sizeof(stack));
    if (!factors)
        return ALLOCATION_ERR;
    *factors = factors_new;
    (*factors)->pow = 0;
    (*factors)->factor = 2;
    (*factors)->next_factor = NULL;
    return OK;
}

int increase_stack(stack **factors)
{
    stack *factors_new = calloc(1, sizeof(stack));
    if (!factors_new)
        return ALLOCATION_ERR;
    factors_new->next_factor = *factors;
    factors_new->factor = (*factors)->factor + 1;
    factors_new->pow = 0;
    *factors = factors_new;
    return OK;
}

void free_stack(stack **factors)
{
    while ((*factors)->next_factor != NULL)
    {
        stack *buff = *factors;
        *factors = (*factors)->next_factor;
        free(buff);
    }
    free(*factors);
    return;
}

void output_stack(FILE *f, stack *factors)
{
    while (factors->next_factor != NULL)
    {
        if (factors->pow > 0)
            fprintf(f, "%d %d ", factors->factor, factors->pow);
        stack *buff = factors;
        factors = factors->next_factor;
        free(buff);
    }
    if (factors->pow > 0)
        fprintf(f, "%d %d 1\n", factors->factor, factors->pow);
    free(factors);
    return;
}
