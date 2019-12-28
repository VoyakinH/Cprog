#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

static int copy_to_struct(exp **experiments, const int i, const int date[], const char *surname, const float *data, const int num_of_data)
{
    (*experiments)[i].technician = calloc(strlen(surname) + 1, sizeof(char));
    (*experiments)[i].data = calloc(num_of_data + 1, sizeof(float));
    if (!(*experiments)[i].technician || !(*experiments)[i].data)
    {
        return ALLOCATION_ERR;
    }

    for (int j = 0; j < DATE_LEN; j++)
    {
        (*experiments)[i].date[j] = date[j];
    }

    strncpy((*experiments)[i].technician, surname, strlen(surname));

    for (int j = 0; j < num_of_data; j++)
    {
        (*experiments)[i].data[j] = data[j];
    }
    (*experiments)[i].num_of_data = num_of_data;

    return OK;
}

int read_set_of_exp(exp **experiments, int *i)
{
    *i = 0;
    int rc = OK;
    int num_of_data = 0;

    char *got_date[100];
    int date[DATE_LEN];
    char *surname[100];

    if (is_date_valid(got_date, date) != 0)
        rc = READ_DATE_ERR;

    while (strcmp(got_date, "00.00.0000") != 0 && rc == OK)
    {
        if (is_date_valid(got_date, date) != 0)
        {
            rc = INVALID_DATE;
            break;
        }

        if (read_technician(&surname, f) != OK)
        {
            rc = ALLOCATION_ERR;
            break;
        }

        float *data = NULL;
        if (read_data(&data, &num_of_data, f) != OK)
        {
            rc = READ_DATA_ERR;
            free(data);
            break;
        }

        if (copy_to_struct(experiments, *i, date, surname, data, num_of_data) != OK)
        {
            rc = ALLOCATION_ERR;
            free(data);
            break;
        }
        free(data);

        (*i)++;
        exp *new_experiments = realloc(*experiments, (*i + 1) * sizeof(exp));
        if (new_experiments)
        {
            *experiments = new_experiments;
            new_experiments = NULL;
        }
        else
        {
            rc = ALLOCATION_ERR;
            break;
        }

        if (!fgets(got_date, GOT_DATE_LEN, f))
        {
            rc = READ_DATE_ERR;
            fgetc(f);
            break;
        }
        if (fgetc(f) != '\n')
        {
            rc = READ_DATE_ERR;
            break;
        }
    }
    free(surname);
    free(got_date);

    return rc;
}

void free_arr(exp **experiments, int number_of_exp)
{
    for (int i = 0; i < number_of_exp; i++)
    {
        free((*experiments)[i].technician);
        free((*experiments)[i].data);
    }
    return;
}
