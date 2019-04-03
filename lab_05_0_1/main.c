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

void arr_check(int array[N][N], int arr1[], int k, int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr1[i] = array[i][k];
    for (i = 0; i < n - 1; i++)
        if (arr1[i] > arr1[i + 1])
        {
            arr1[k] = 0;
            return;
        }
    arr1[k] = 1;
    return;
}

void arr_print(int arr1[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    return;
}

int main(void)
{
    int n, m, k;
    printf("Введите кол-во строк матрицы, столбцов матрицы, К: ");
    int rs = scanf("%d %d %d", &n, &m, &k);
    if (rs != 3 || n > 10 || m > 10 || n <= 0 || m <= 0 || k > m || k > n || k < 1)
    {
        printf("Данные введены неверно.");
        return 1;
    }
    k--;
    int array[N][N];
    if (arr_input(array, n, m) == 1)
    {
        printf("Данные введены неверно.");
        return 1;
    }
    int arr1[n];
    arr_check(array, arr1, k, n);
    arr_print(arr1, n);
    return 0;
}
