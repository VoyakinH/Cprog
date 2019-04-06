#include <stdio.h>
#define N 10

int arr_input(int array[N][N], int n, int m)
{
    int i, j, rs;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            rs = scanf("%d", &array[i][j]);
            if (rs != 1)
                return -1;
        }
    return 0;
}

void arr_check(int array[N][N], int arr1[N], int n, int m)
{
    int i, j, ok;
    for (i = 0; i < m; i++)
    {
        ok = 1;
        for (j = 0; j < n - 1; j++)
            if (array[j][i] < array[j + 1][i])
                ok = 0;
        if (ok == 1)
            arr1[i] = 1;
        else
            arr1[i] = 0;
    }
    return;
}

void arr_print(int arr1[], int m)
{
    for (int i = 0; i < m; i++)
        printf("%d ", arr1[i]);
    return;
}

int main(void)
{
    int n, m, rs;
    printf("Введите кол-во строк матрицы, столбцов матрицы: ");
    rs = scanf("%d %d", &n, &m);
    if (rs != 2 || n > 10 || m > 10 || n <= 0 || m <= 0)
    {
        printf("Данные введены неверно.");
        return 1;
    }
    int array[N][N];
    if (arr_input(array, n, m) == -1)
    {
        printf("Данные введены неверно.");
        return 1;
    }
    int arr1[N];
    arr_check(array, arr1, n, m);
    arr_print(arr1, m);
    return 0;
}
