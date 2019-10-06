#include <stdio.h>
#include <inttypes.h>
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

int main()
{
    int count = 0;
    count += read_two_int_work_cor();
    count += read_two_power_work_cor();
    printf("Test functions passed %d of 2\n", count);
    return 0;
}
