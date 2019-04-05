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
        while (j < m)
        {
            if (summ_chsl(array[i][j]) % 2 == 1)
                ok++;
            j++;
        }
        if (ok > 1)
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
        for (j = 0; j < m; j++)
            printf("%d ", array[i][j]);
    return;
}

int main(void)
{
    int rs, n, m;
    rs = scanf("%d %d", &n, &m);
    if (rs != 2 || n > 10 || m > 10 || rs == EOF || m < 1 || n < 1)
        return 1;
    int array[N][N];
    if (arr_input(array, n, m) == -1)
        return 1;
    n = arr_check(array, n, m);
    arr_print(array, n, m);
    return 0;
}
