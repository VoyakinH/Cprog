#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "defines.h"

static int read_mode_work_corr()
{
    char input[5][30];
    strcpy(input[0], "mul\n");
    strcpy(input[1], "out\n");
    strcpy(input[2], "ou1\n");
    strcpy(input[3], "ou\n");
    strcpy(input[4], "outt");
    char output[5];
    int expected[5] = { OK, OK, OK, READ_MODE_ERR, READ_MODE_ERR };
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        FILE *f = fopen("buff.txt", "w+");
        fprintf(f, "%s", input[i]);
        rewind(f);
        if (read_mode(f, output) == expected[i])
            count++;
        fclose(f);
    }
    int res = 0;
    printf("read_mode: ");
    if (count == 5)
        printf("OK\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        res++;
    return res;
}

static int read_int_work_corr()
{
    char input[5][30];
//    strcpy(input[0], "1");
    strcpy(input[1], "-1\n");
    strcpy(input[2], "a 0\n");
    strcpy(input[3], "1 1");
    strcpy(input[4], "1\n1");
    int val;
    int expected[5] = { READ_INT_ERR, READ_INT_ERR, READ_INT_ERR, OK, OK };
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        FILE *f = fopen("buff.txt", "w+");
        fprintf(f, "%s", input[i]);
        rewind(f);
        if (read_int(f, &val) == expected[i])
            count++;
        fclose(f);
    }
    int res = 0;
    printf("read_int: ");
    if (count == 5)
        printf("OK\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        res++;
    return res;
}

int main()
{
    int count = 0;
    count += read_mode_work_corr();
    count += read_int_work_corr();

    printf("Test functions passed %d of 2\n", count);
    return 0;
}

