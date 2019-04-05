#include <stdio.h>
#define N 10

int arr_input(int array[N][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (scanf("%d", &array[i][j]) != 1)
                return -1;
    return 1;
}

void sort(int array[N][N], int n, int m)
{
    int i1, i2, j, k, x1, x2, x;
    for (i1 = 0; i1 < n - 1; i1++)
    {
        x1 = 1;
        for (k = 0; k < m; k++)
            x1 *= array[i1][k];
        for (i2 = i1 + 1; i2 < n; i2++)
        {
            x2 = 1;
            for (k = 0; k < m; k++)
                x2 *= array[i2][k];
            if (x1 > x2)
                for (k = 0; k < m; k++)
                {
                    x = array[i1][k];
                    array[i1][k] = array[i2][k];
                    array[i2][k] = x;
                }
        }
    }
}

void arr_print(int array[N][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    return;
}

int main(void)
{
    int rs, i, j, n, m;
    if (scanf("%d %d", &n, &m) != 2 || n > 10 || m > 10 || m < 1 || n < 1)
    {
        printf("Данные введены неверно");
        return 1;
    }
    int array[N][N];
    if (arr_input(array, n, m) == -1)
    {
        printf("Данные введены неверно");
        return 1;
    }
    sort(array, n, m);
    arr_print(array, n, m);
    return 0;
}
