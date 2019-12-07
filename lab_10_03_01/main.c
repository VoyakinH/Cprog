#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "func.h"

int main()
{
    exp *experiments = malloc(sizeof(exp));
    int number_of_exp;

    if (read_set_of_exp(&experiments, &number_of_exp, stdin) != OK)
    {
        free_arr(&experiments, number_of_exp);
        free(experiments);
        return READ_EXP_ERR;
    }

    for (int i = 0; i < number_of_exp; i++)
        if (experiments[i].num_of_data > 1)
        {
            experiments[i].data[0] = average_data(experiments, i);
            experiments[i].num_of_data = 1;
        }

    make_del(experiments, &number_of_exp);

    if (number_of_exp == 0)
    {
        free_arr(&experiments, number_of_exp);
        free(experiments);
        return READ_EXP_ERR;
    }

    char key[KEY_LEN];

    if (read_key(key, stdin) != OK || sort_arr(experiments, number_of_exp, key) != OK)
    {
        free_arr(&experiments, number_of_exp);
        free(experiments);
        return READ_KEY_ERR;
    }

    FILE *f = fopen("results.txt", "w");
    if (!f)
    {
        free_arr(&experiments, number_of_exp);
        free(experiments);
        return FILE_OPEN_ERR;
    }

    write_to_file(f, experiments, number_of_exp);
    free_arr(&experiments, number_of_exp);

    free(experiments);
    fclose(f);
    return OK;
}
