#include <stdio.h>
#include "func.h"

int read_n_must_return_cor_res()
{
    int expected[4] = { 13, 183, 3, 71 };
    int actual, count = 0;
    int n;
    FILE *f;
    f = fopen("test.txt", "r");
    for (int i = 0; i < 4; i++)
    {
        read_n(f, &n);
        actual = n;
        if (actual == expected[i])
            count++;
    }
    fclose(f);
    if (count == 4)
        printf("\read_n function: OK\n");
    else
        printf("read_n function: Failed\n");
    printf("Tests passed %d of 4\n\n", count);
    if (count == 4)
        return 1;
    return 0;
}

int main()
{
    int count = 0;
    count += read_n_must_return_cor_res();
    printf("Test functions passed %d of 3\n", count);
    return 0;
}
