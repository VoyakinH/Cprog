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

void arr_check(int array[N][N], int arr1[], int k, int n, int m)
{
    int i, j;
    int l = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            arr1[l] = array[i][j];
            l++;
        }
    for (i = 0; i < n - 1; i++)
        if (array[i][k] < array[i + 1][k])
        {
            arr1[k] = 0;
            return;
        }
    arr1[k] = 1;
    return;
}

void arr_print(int arr1[], int n, int m)
{
    n *= m;
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    return;
}

int main(void)
{
    int n, m, k, rs;
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
    printf("Введите K: ");
    rs = scanf("%d", &k);
    if (k >= m || k >= n || k < 0 || rs != 1)
    {
        printf("Данные введены неверно.");
        return 1;
    }
    int arr1[N * N];
    arr_check(array, arr1, k, n, m);
    arr_print(arr1, n, m);
    return 0;
}
