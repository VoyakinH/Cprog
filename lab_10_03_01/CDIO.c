#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

void write_to_file(FILE *f, exp *experiments, int number_of_exp)
{
    for (int i = 0; i < number_of_exp; i++)
    {
        if (experiments[i].date[0] < 10)
        {
            fprintf(f, "0%d.", experiments[i].date[0]);
        }
        else
        {
            fprintf(f, "%d.", experiments[i].date[0]);
        }
        if (experiments[i].date[1] < 10)
        {
            fprintf(f, "0%d.%d\n", experiments[i].date[1], experiments[i].date[2]);
        }
        else
        {
            fprintf(f, "%d.%d\n", experiments[i].date[1], experiments[i].date[2]);
        }

        fprintf(f, "%s\n", experiments[i].technician);

        fprintf(f, "%d %f\n", experiments[i].num_of_data, experiments[i].data[0]);
    }
    return;
}

int read_key(char key[], FILE *f)
{
    if (fgets(key, KEY_LEN, f) == NULL)
    {
        return READ_KEY_ERR;
    }
    return OK;
}
