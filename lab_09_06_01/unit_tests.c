#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int read_two_int_work_cor()
{
    int a[10] = { -1, 0, 300, 401, 505, 6, 7, 8, 9, 10 };
    int expected[10] = { -1, 0, 300, 401, 505, 6, 7, 8, 9, 10 };
    int count = 0;
    int x, y;
    FILE *buff = fopen("buff.txt", "w+");
    for (int i = 0; i < 9; i += 2)
    {
        fprintf(buff, "%d %d ", a[i], a[i + 1]);
    }
    fseek(buff, 0, SEEK_SET);
    for (int i = 0; i < 9; i += 2)
    {
        read_two_int(buff, &x, &y);
        if (x == expected[i] && y == expected[i + 1])
            count++;
    }
    fclose(buff);
    if (count == 5)
        printf("read_two_int: OK\n");
    else
        printf("read_two_int: Failed\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        return 1;
    return 0;
}

int read_two_power_work_cor()
{
    int a[10] = { -1, 0, 300, 401, 505, 6, 7, 8, 9, 10 };
    int expected[10] = { -1, 0, 300, 401, 505, 6, 7, 8, 9, 10 };
    int count = 0;
    int x, y;
    FILE *buff = fopen("buff.txt", "w+");
    for (int i = 0; i < 9; i += 2)
    {
        fprintf(buff, "%d %d ", a[i], a[i + 1]);
    }
    fseek(buff, 0, SEEK_SET);
    for (int i = 0; i < 9; i += 2)
    {
        read_two_power(buff, &x, &y);
        if (x == expected[i] && y == expected[i + 1])
            count++;
    }
    fclose(buff);
    if (count == 5)
        printf("read_two_int: OK\n");
    else
        printf("read_two_int: Failed\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        return 1;
    return 0;
}

int out_arr_work_cor()
{
    int i = 0;
    int64_t x = 0;
    int count = 0;
    int count_buff = 0;
    int64_t *a_1 = malloc(1 * sizeof(int64_t));
    int64_t *a_2 = malloc(4 * sizeof(int64_t));
    int64_t *a_3 = malloc(9 * sizeof(int64_t));
    int64_t *a_4 = malloc(16 * sizeof(int64_t));
    a_1[0] = -1;
    for (i = 0; i < 4; i++)
        *(a_2 + i) = i;
    for (i = 0; i < 9; i++)
        *(a_3 + i) = i;
    for (i = 0; i < 16; i++)
        *(a_4 + i) = i;
    FILE *buff = fopen("buff.txt", "w+");
    out_arr(buff, &a_1, 1, 1);
    out_arr(buff, &a_2, 1, 4);
    out_arr(buff, &a_3, 1, 9);
    out_arr(buff, &a_4, 1, 16);
    rewind(buff);
    fscanf(buff, "%" PRId64, &x);
    if (x == a_1[0])
        count++;
    for (i = 0; i < 4; i++)
    {
        fscanf(buff, "%" PRId64, &x);
        if (x == a_2[i])
            count_buff++;
    }
    if (count_buff == 4)
        count++;
    count_buff = 0;
    for (i = 0; i < 9; i++)
    {
        fscanf(buff, "%" PRId64, &x);
        if (x == a_3[i])
            count_buff++;
    }
    if (count_buff == 9)
        count++;
    count_buff = 0;
    for (i = 0; i < 16; i++)
    {
        fscanf(buff, "%" PRId64, &x);
        if (x == a_4[i])
            count_buff++;
    }
    if (count_buff == 16)
        count++;
    fclose(buff);
    free(a_1);
    free(a_2);
    free(a_3);
    free(a_4);
    if (count == 4)
        printf("out_arr: OK\n");
    else
        printf("out_arr: Failed\n");
    printf("Tests passed %d of 4\n\n", count);
    if (count == 4)
        return 1;
    return 0;
}

int main()
{
    int count = 0;
    count += read_two_int_work_cor();
    count += read_two_power_work_cor();
    count += out_arr_work_cor();
    printf("Test functions passed %d of 3\n", count);
    return 0;
}
