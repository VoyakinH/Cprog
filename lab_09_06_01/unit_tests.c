#include <stdio.h>
#include <inttypes.h>
#include "func.h"
#include "defines.h"

int read_two_int_must_return_cor_res()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int expected[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int count = 0;
    int x, y;
    for (int i = 0; i < 10; i += 2)
    {
        fprintf(stdin, "%d %d", a[i], a[i + 1]);
        read_two_int(stdin, &x, &y);
        if (x == expected[i] && y == expected[i + 1])
            count++;
    }
    if (count == 10)
        printf("\read_two_int: OK\n");
    else
        printf("read_two_int: Failed\n");
    printf("Tests passed %d of 10\n\n", count);
    if (count == 10)
        return 1;
    return 0;
}

int main()
{
    int count = 0;
    count += read_two_int_must_return_cor_res();
    printf("Test functions passed %d of 1\n", count);
    return 0;
}
