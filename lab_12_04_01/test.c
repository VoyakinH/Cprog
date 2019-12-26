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
    char output[10];
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
    strcpy(input[0], "1");
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

static int init_list_work_corr()
{
    list *factors = NULL;
    int count = 0;
    if (init_list(&factors) == OK && factors != NULL && factors->pow == 0 && factors->factor == 2 && factors->next_factor == NULL)
        count++;
    free_list(&factors);
    int res = 0;
    printf("init_list: ");
    if (count == 1)
        printf("OK\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        res++;
    return res;
}

static int increase_list_work_corr()
{
    list *factors = NULL;
    int count = 0;
    init_list(&factors);
    if (increase_list(&factors) == OK && factors->next_factor != NULL && factors->pow == 0 && factors->factor == 3)
        count++;
    free_list(&factors);
    int res = 0;
    printf("increase_list: ");
    if (count == 1)
        printf("OK\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        res++;
    return res;
}

static int output_list_work_corr()
{
    list *factors = NULL;
    int count = 0;
    init_list(&factors);
    factors->factor = 5;
    factors->pow = 5;
    FILE *f = fopen("buff.txt", "w+");
    output_list(f, factors);
    rewind(f);
    int x, y;
    if (fscanf(f, "%d%d", &x, &y) == 2 && x == factors->factor && y == factors->pow)
        count++;
    int res = 0;
    printf("output_list: ");
    if (count == 1)
        printf("OK\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        res++;
    return res;
}

static int int_to_list_work_corr()
{
    char input[5][30];
    strcpy(input[0], "0");
    strcpy(input[1], "1\n");
    strcpy(input[2], "2\n");
    strcpy(input[3], "50\n");
    strcpy(input[4], "35\n");
    int expected[5] = { READ_INT_ERR, OK, OK, OK, OK };
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        FILE *f = fopen("buff.txt", "w+");
        fprintf(f, "%s", input[i]);
        list *factors = NULL;
        rewind(f);
        if (int_to_list(f, &factors) == expected[i])
            count++;
        fclose(f);
        if (factors != NULL)
            free_list(&factors);
    }
    int res = 0;
    printf("int_to_list: ");
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
    count += init_list_work_corr();
    count += increase_list_work_corr();
    count += output_list_work_corr();
    count += int_to_list_work_corr();
    
    printf("Test functions passed %d of 6\n", count);
    return 0;
}

