#include <stdio.h>
#define N 20

int arr_input(int array[N][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (scanf("%d", &array[i][j]) != 1)
                return -1;
    return 1;
}

int summ_chsl(int x)
{
    int s;
    s = 0;
    if (x < 0)
        x *= -1;
    while (x > 0)
    {
        s += x % 10;
        x = x / 10;
    }
    return s;
}

int arr_check(int array[N][N], int n, int m)
{
    int i, j, a, ok;
    i = 0;
    while (i < n)
    {
        ok = 0;
        j = 0;
        while (j < m - 1)
        {
            a = j + 1;
            while (a < m)
            {
                if ((summ_chsl(array[i][j]) + summ_chsl(array[i][a])) % 2 == 1)
                {
                    j = m - 1;
                    a = m;
                    ok = 1;
                }
                a++;
            }
            j++;
        }
        if (ok == 1)
        {
            n++;
            for (j = 0; j < m; j++)
                for (a = n - 1; a > i - 1; a--)
                    array[a][j] = array[a - 1][j];
            for (j = 0; j < m; j++)
                array[i][j] = -1;
            i++;
        }
        i++;
    }
    return n;
}

void arr_print(int array[N][N], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ", array[i][j]);
        if (i != n - 1)
            printf("\n");
    }
    return;
}

int main(void)
{
    int rs, n, m, k;
    printf("Введите кол-во строк и столбцов через пробел: \n");
    rs = scanf("%d %d", &n, &m);
    if (rs != 2 || n > 10 || m > 10 || rs == EOF || m < 2 || n < 1)
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
    k = arr_check(array, n, m);
    if (k == n)
        return 1;
    arr_print(array, k, m);
    return 0;
}
