#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"
#include "defines.h"

int is_date_valid(const char *got_date, int date[])
{
    int count = 0;
    for (int i = 0; i < GOT_DATE_LEN - 1; i++)
    {
        if (got_date[i] == '.')
            count++;
        else if (!isdigit(got_date[i]))
            count = 3;
    }

    if (count != 2)
        return INVALID_DATE;
    if (got_date[2] != '.' || got_date[5] != '.')
        return INVALID_DATE;

    date[0] = atoi(got_date);
    date[1] = atoi(got_date + 3);
    date[2] = atoi(got_date + 6);

    if (((date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) && date[0] > 30)
        || date[0] > 31 || date[1] > 12 || date[0] <= 0 || date[1] <= 0 || date[2] < 1000)
    {
        return INVALID_DATE;
    }
    
    if (date[1] == 2 && (((date[2] % 4 != 0 || (date[2] % 100 == 0 && date[2] % 400 != 0)) && date[0] > 28) || date[0] > 29))
    {
        return INVALID_DATE;
    }

    return OK;
}

int read_technician(char **surname, FILE *f)
{
    int j = 0;
    char elem = fgetc(f);

    while (elem != '\n')
    {
        if (!isalpha(elem))
            return READ_TECHNICIAN_ERR;

        (*surname)[j] = elem;
        j++;

        char *new_surname = realloc(*surname, (j + 1) * sizeof(char));
        if (new_surname)
        {
            *surname = new_surname;
            new_surname = NULL;
        }
        else
            return ALLOCATION_ERR;

        elem = fgetc(f);
    }
    (*surname)[j] = '\0';

    return OK;
}

int read_data(float **data, int *num_of_data, FILE *f)
{
    if (fscanf(f, "%d", num_of_data) != 1 || *num_of_data < 1)
        return READ_DATA_ERR;

    *data = calloc(*num_of_data, sizeof(float));
    if (!*data)
        return ALLOCATION_ERR;

    for (int j = 0; j < *num_of_data; j++)
        if (fscanf(f, "%f", &(*data)[j]) != 1)
            return READ_DATA_ERR;

    fgetc(f);

    return OK;
}
