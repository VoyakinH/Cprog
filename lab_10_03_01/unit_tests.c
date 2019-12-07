#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "defines.h"

static int read_set_of_exp_work_corr()
{
    char a[12][64];
    strcpy(a[0], "19.0..2001\n");
    strcpy(a[1], "29.02.2001\n");
    strcpy(a[2], "19.01.2001\nvoyakin1\n");
    strcpy(a[3], "19.01.2001\nvoyakin\n0\n");
    strcpy(a[4], "19.01.2001\nvoyakin\n1 1\n00.00.0000\nDATA\n");
    strcpy(a[5], "19.01.0100\n");
    strcpy(a[6], "19.01.1991\nvoyakin\n2 1 2\n00.00.0000\nTECHNICIAN");
    strcpy(a[7], "19.01.2001\nvoyakin alexei\n");
    strcpy(a[8], "19.01.2001\nvoyakin\n1 1\n00.00.0000\nDATE");
    strcpy(a[9], "29.02.1700\n");
    strcpy(a[10], "19.01.2001\nvoy1kin\n1 1\n00.00.0000\nDATA\n");
    strcpy(a[11], "19.01.2001\nvoyakin\n1 a\n");
    
    int expected[12] = { READ_DATE_ERR, READ_DATE_ERR, ALLOCATION_ERR, READ_DATA_ERR, OK, READ_DATE_ERR, OK, ALLOCATION_ERR, OK, READ_DATE_ERR, ALLOCATION_ERR, READ_DATA_ERR };
    int count = 0;
    for (int i = 0; i < 12; i++)
    {
        exp *experiments = malloc(sizeof(exp));
        int number_of_exp = 0;
        FILE *f = fopen("buff.txt", "w+");
        fprintf(f, "%s", a[i]);
        rewind(f);
        if (read_set_of_exp(&experiments, &number_of_exp, f) == expected[i])
            count++;
        fclose(f);
        free_arr(&experiments, number_of_exp);
        free(experiments);
    }

    int res = 0;
    printf("read_set_of_exp: ");
    if (count == 12)
        printf("OK\n");
    printf("Tests passed %d of 12\n\n", count);
    if (count == 12)
        res++;
    return res;
}

static int average_data_work_corr()
{
    char a[128];
    strcpy(a, "19.01.2001\nv\n2 1 2\n19.01.2001\nv\n3 1 2 3\n19.01.2001\nv\n4 1 2 -6 2\n00.00.0000\nTECHNICIAN");

    exp *experiments = malloc(sizeof(exp));
    int number_of_exp = 0;

    FILE *f = fopen("buff.txt", "w+");
    fprintf(f, "%s", a);

    rewind(f);

    read_set_of_exp(&experiments, &number_of_exp, f);
    fclose(f);

    float expected[3] = { 1.500000, 2.000000, -0.250000 };

    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (average_data(experiments, i) == expected[i])
            count++;
    }

    free_arr(&experiments, number_of_exp);
    free(experiments);

    int res = 0;
    printf("average_data: ");
    if (count == 3)
        printf("OK\n");
    printf("Tests passed %d of 3\n\n", count);
    if (count == 3)
        res++;
    return res;
}

static int make_del_work_corr()
{
    char a[128];
    strcpy(a, "30.01.1993\nv\n1 1\n01.02.1993\nv\n1 1\n01.01.1992\nv\n1 1\n00.00.0000\nTECHNICIAN");

    exp *experiments = malloc(sizeof(exp));
    int number_of_exp = 0;

    FILE *f = fopen("buff.txt", "w+");
    fprintf(f, "%s", a);

    rewind(f);

    read_set_of_exp(&experiments, &number_of_exp, f);
    fclose(f);
    
    make_del(experiments, &number_of_exp);
    int count = 0;
    if (number_of_exp == 1 && experiments[0].date[0] == 1 && experiments[0].date[1] == 2 && experiments[0].date[2] == 1993)
        count++;

    free_arr(&experiments, number_of_exp);
    free(experiments);

    int res = 0;
    printf("make_del: ");
    if (count == 1)
        printf("OK\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        res++;
    return res;
}

static int read_key_work_corr()
{
    char a[4][16];
    int returned[4] = { 0, 0, 0, READ_KEY_ERR };
    strcpy(a[0], "TECHNICIAN\n");
    strcpy(a[1], "DATA\n");
    strcpy(a[2], "DATE\n");
    strcpy(a[3], "");

    FILE *f = fopen("buff.txt", "w+");
    fprintf(f, "%s%s%s%s", a[0], a[1], a[2], a[3]);

    rewind(f);

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        char key[KEY_LEN] = "\0";
        if (read_key(key, f) == returned[i] && strcmp(key, a[i]) == 0)
            count++;
    }

    fclose(f);

    int res = 0;
    printf("read_key: ");
    if (count == 4)
        printf("OK\n");
    printf("Tests passed %d of 4\n\n", count);
    if (count == 4)
        res++;
    return res;
}

static int write_to_file_work_corr()
{
    char a[8][16];
    strcpy(a[0], "19.01.2001");
    strcpy(a[1], "voyakin");
    strcpy(a[2], "1 1.000000");
    strcpy(a[3], "01.10.2001");
    strcpy(a[4], "voy");
    strcpy(a[5], "1 1");
    strcpy(a[6], "00.00.0000");
    strcpy(a[7], "DATE");

    FILE *f = fopen("buff.txt", "w+");
    for (int i = 0; i < 8; i++)
        fprintf(f, "%s\n", a[i]);
    rewind(f);

    exp *experiments = malloc(sizeof(exp));
    int number_of_exp = 0;
    
    read_set_of_exp(&experiments, &number_of_exp, f);
    fclose(f);

    f = fopen("buff.txt", "w+");
    write_to_file(f, experiments, number_of_exp);
    rewind(f);
    
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        fgets(a[6], 16, f);
        if (strstr(a[6], a[i]))
            count++;
    }
    fclose(f);
    free_arr(&experiments, number_of_exp);
    free(experiments);

    int res = 0;
    printf("write_to_file: ");
    if (count == 6)
        printf("OK\n");
    printf("Tests passed %d of 6\n\n", count);
    if (count == 6)
        res++;
    return res;
}

static int sort_arr_work_corr()
{
    char a[128];
    strcpy(a, "19.01.2001\nvoyakiny\n1 1.500000\n18.01.2001\nvoyakinx\n1 1.000000\n19.01.2001\nvoyakiny\n1 1.500000\n00.00.0000");

    FILE *f = fopen("buff.txt", "w+");
    fprintf(f, "%s", a);
    rewind(f);

    exp *experiments = malloc(sizeof(exp));
    int number_of_exp = 0;
    
    read_set_of_exp(&experiments, &number_of_exp, f);
    fclose(f);
    
    int count = 0;

    sort_arr(experiments, number_of_exp, "DATE\n");
    if (experiments[0].date[0] == 18)
        count++;

    sort_arr(experiments, number_of_exp, "TECHNICIAN\n");
    if (strcmp(experiments[0].technician, "voyakinx") == 0)
        count++;

    sort_arr(experiments, number_of_exp, "DATA\n");
    if (experiments[0].data[0] == 1.000000)
        count++;

    if (sort_arr(experiments, number_of_exp, "INVALID\n") != OK)
        count++;

    free_arr(&experiments, number_of_exp);
    free(experiments);

    int res = 0;
    printf("sort_arr: ");
    if (count == 4)
        printf("sort_arr: OK\n");
    printf("Tests passed %d of 4\n\n", count);
    if (count == 4)
        res++;
    return res;
}

static int is_date_valid_work_corr()
{
    char a[6][16];
    int out[3];
    strcpy(a[0], "01.01.2001");
    strcpy(a[1], "010.1.2001");
    strcpy(a[2], "01.0a.2001");
    strcpy(a[3], "32.01.2001");
    strcpy(a[4], "30.02.2001");

    int count = 0;
    for (int i = 1; i < 5; i++)
    {
        if (is_date_valid(a[i], out) != OK)
            count++;
    }
    if (is_date_valid(a[0], out) == OK)
        count++;

    int res = 0;
    printf("is_date_valid: ");
    if (count == 5)
        printf("OK\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        res++;
    return res;
}

static int compare_work_corr()
{
    int count = 0;
    exp *exper = malloc(sizeof(exp) * 2);

    exper[0].date[2] = 2001;
    exper[1].date[2] = 2000;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[2] == 2000)
        count++;

    exper[0].date[2] = 2000;
    exper[1].date[2] = 2001;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[2] == 2000)
        count++;

    exper[0].date[2] = 2000;
    exper[1].date[2] = 2000;

    exper[0].date[1] = 10;
    exper[1].date[1] = 11;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[1] == 10)
        count++;

    exper[0].date[1] = 11;
    exper[1].date[1] = 10;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[1] == 10)
        count++;

    exper[0].date[1] = 1;
    exper[1].date[1] = 1;

    exper[0].date[0] = 1;
    exper[1].date[0] = 2;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[0] == 1)
        count++;

    exper[0].date[0] = 2;
    exper[1].date[0] = 1;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[0] == 1)
        count++;

    exper[0].date[0] = 1;
    exper[1].date[0] = 1;
    qsort(exper, 2, sizeof(exp), comp_date);
    if (exper[0].date[0] == 1)
        count++;

    exper[0].data = malloc(sizeof(float));
    exper[1].data = malloc(sizeof(float));

    exper[0].data[0] = 1;
    exper[1].data[0] = 2;
    qsort(exper, 2, sizeof(exp), comp_float);
    if (exper[0].data[0] == 1)
        count++;

    exper[0].data[0] = 2;
    exper[1].data[0] = 1;
    qsort(exper, 2, sizeof(exp), comp_float);
    if (exper[0].data[0] == 1)
        count++;

    exper[0].data[0] = 1;
    exper[1].data[0] = 1;
    qsort(exper, 2, sizeof(exp), comp_float);
    if (exper[0].data[0] == 1)
        count++;

    free(exper[0].data);
    free(exper[1].data);
    free(exper);

    int res = 0;
    printf("comp_functions: ");
    if (count == 10)
        printf("OK\n");
    printf("Tests passed %d of 10\n\n", count);
    if (count == 10)
        res++;
    return res;
}

int main()
{
    int count = 0;
    count += read_set_of_exp_work_corr();
    count += average_data_work_corr();
    count += make_del_work_corr();
    count += read_key_work_corr();
    count += write_to_file_work_corr();
    count += sort_arr_work_corr();
    count += is_date_valid_work_corr();
    count += compare_work_corr();

    printf("Test functions passed %d of 8\n", count);
    return 0;
}
