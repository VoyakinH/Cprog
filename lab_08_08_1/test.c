#include <stdio.h>
#include "func.h"

int read_n_must_return_cor_res(FILE *f)
{
    int expected[5] = { 13, 183, 3, 71, 100 };
    int actual, count = 0;
    int n;
    for (int i = 0; i < 5; i++)
    {
        read_n(f, &n);
        actual = n;
        if (actual == expected[i])
            count++;
    }
    if (count == 5)
        printf("\read_n function: OK\n");
    else
        printf("read_n function: Failed\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        return 1;
    return 0;
}

int read_p_must_return_cor_res(FILE *f)
{
    int expected[5] = { 0, 1, 2, 3, 4 };
    int actual, count = 0;
    int p = 0;
    for (int i = 0; i < 5; i++)
    {
        read_p(f, &p, 100);
        actual = p;
        if (actual == expected[i])
            count++;
    }
    if (count == 5)
        printf("\read_n function: OK\n");
    else
        printf("read_n function: Failed\n");
    printf("Tests passed %d of 5\n\n", count);
    if (count == 5)
        return 1;
    return 0;
}

int main()
{
    int count = 0;
    FILE *f = fopen("test.txt", "r");
    count += read_n_must_return_cor_res(f);
    count += read_p_must_return_cor_res(f);
    fclose(f);
    printf("Test functions passed %d of 2\n", count);
    return 0;
}
