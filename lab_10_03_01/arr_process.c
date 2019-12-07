#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defines.h"
#include "func.h"

float average_data(const exp *experiments, int i)
{
    float sum = 0;
    for (int j = 0; j < experiments[i].num_of_data; j++)
    {
        sum += experiments[i].data[j];
    }

    sum /= experiments[i].num_of_data;

    return sum;
}

static int check_date(exp experiment)
{
    int mounth = experiment.date[1];
    int year = experiment.date[2];

    if (year < 1993)
        return 1;

    if (mounth < 2 && year == 1993)
        return 1;

    return 0;
}

static void delete_exp(exp *experiments, int i, int number_of_exp)
{
    free(experiments[i].technician);
    free(experiments[i].data);

    for (int j = i; j < number_of_exp - 1; j++)
    {
        experiments[j] = experiments[j + 1];
    }
    return;
}

void make_del(exp *experiments, int *number_of_exp)
{
    int i = 0;
    while (i < *number_of_exp)
    {
        if (check_date(experiments[i]) == 1)
        {
            delete_exp(experiments, i, *number_of_exp);
            (*number_of_exp)--;
        }
        else
            i++;
    }
    return;
}

int comp_string(const void *x1, const void *x2)
{
    const exp *xx1 = x1;
    const exp *xx2 = x2;

    return (strcmp(xx1->technician, xx2->technician));
}

int comp_float(const void *x1, const void *x2)
{
    const exp *xx1 = x1;
    const exp *xx2 = x2;

    if (xx1->data[0] > xx2->data[0])
        return 1;
    if (xx1->data[0] < xx2->data[0])
        return -1;

    return 0;
}

int comp_date(const void *x1, const void *x2)
{
    const exp *xx1 = x1;
    const exp *xx2 = x2;

    if (xx1->date[2] > xx2->date[2])
        return 1;
    if (xx1->date[2] < xx2->date[2])
        return -1;
    if (xx1->date[1] > xx2->date[1])
        return 1;
    if (xx1->date[1] < xx2->date[1])
        return -1;
    if (xx1->date[0] > xx2->date[0])
        return 1;
    if (xx1->date[0] < xx2->date[0])
        return -1;

    return 0;
}

int sort_arr(exp *experiments, int number_of_exp, const char *key)
{
    if (strcmp(key, "DATE\n") == 0)
    {
        qsort(experiments, number_of_exp, sizeof(exp), comp_date);
        return OK;
    }

    if (strcmp(key, "TECHNICIAN\n") == 0)
    {
        qsort(experiments, number_of_exp, sizeof(exp), comp_string);
        return OK;
    }

    if (strcmp(key, "DATA\n") == 0)
    {
        qsort(experiments, number_of_exp, sizeof(exp), comp_float);
        return OK;
    }

    return READ_KEY_ERR;
}
