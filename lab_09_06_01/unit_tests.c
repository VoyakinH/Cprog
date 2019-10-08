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

int read_array_work_cor()
{
    int i, j, count_buff, count = 0, rc;
    int64_t *a = NULL, **a_p = NULL;
    FILE *buff = fopen("buff.txt", "w+");
    for (i = 1; i < 5; i++)
    {
        rewind(buff);
        for (j = 0; j < i * i; j++)
            fprintf(buff, "%d ", j);
        rewind(buff);
        rc = read_array(buff, i, i, &a, &a_p);
        count_buff = 0;
        for (j = 0; j < i * i; j++)
            if (a[j] == j)
                count_buff++;
        if (count_buff == i * i && rc == OK)
            count++;
        free(a);
        free(a_p);
    }
    fclose(buff);
    if (count == 4)
        printf("read_arr: OK\n");
    else
        printf("read_arr: Failed\n");
    printf("Tests passed %d of 4\n\n", count);
    if (count == 4)
        return 1;
    return 0;
}

int create_arr_work_cor()
{
    int64_t *a = NULL, **a_p = NULL;
    int count = 0;
    if (create_arr(&a, &a_p, 10) == OK)
        count++;
    free(a);
    free(a_p);
    if (count == 1)
        printf("create_arr: OK\n");
    else
        printf("create_arr: Failed\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        return 1;
    return 0;
}

int new_size_work_cor()
{
    int rc, count = 0;
    int64_t *a = malloc(2 * 2 * sizeof(int64_t));
    int64_t **a_p = malloc(2 * sizeof(int64_t*));
    rc = new_size(&a, &a_p, 4, 4);
    if (rc == OK)
        count++;
    free(a);
    free(a_p);
    if (count == 1)
        printf("new_size: OK\n");
    else
        printf("new_size: Failed\n");
    printf("Tests passed %d of 1\n\n", count);
    if (count == 1)
        return 1;
    return 0;
}

int make_square_work_cor()
{
    int n = 2, m = 3, i, rc, count = 0;
    int64_t *a = malloc(n * m * sizeof(int64_t));
    int64_t **a_p = malloc(n * sizeof(int64_t*));
    for (i = 0; i < n; i++)
        a_p[i] = a + i * m;
    for (i = 0; i < n * m; i++)
        a[i] = i;
    rc = make_square(&a, &a_p, &n, &m);
    if (rc == OK && a_p[0][0] == 1 && a_p[0][1] == 2 && a_p[1][0] == 4 &&
        a_p[1][1] == 5 && n == 2 && m == 2)
        count++;
    free(a);
    free(a_p);
    n = 2;
    m = 1;
    a = malloc(n * m * sizeof(int64_t));
    a_p = malloc(n * sizeof(int64_t*));
    for (i = 0; i < n; i++)
        a_p[i] = a + i * m;
    for (i = 0; i < n * m; i++)
        a[i] = i;
    rc = make_square(&a, &a_p, &n, &m);
    if (rc == OK && a_p[0][0] == 1)
        count++;
    free(a);
    free(a_p);
    if (count == 2)
        printf("make_square: OK\n");
    else
        printf("make_squeare: Failed\n");
    printf("Tests passed %d of 2\n\n", count);
    if (count == 2)
        return 1;
    return 0;
}
int main()
{
    int count = 0;
    count += read_two_int_work_cor();
    count += read_two_power_work_cor();
    count += out_arr_work_cor();
    count += read_array_work_cor();
    count += create_arr_work_cor();
    count += new_size_work_cor();
    count += make_square_work_cor();
    printf("Test functions passed %d of 7\n", count);
    return 0;
}