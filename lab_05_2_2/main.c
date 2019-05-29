#include <stdio.h>
#define N 20

int size_input(int *n, int *m)
{
    if (scanf("%d %d", &*n, &*m) != 2)
        return -1;
    if (*n > 10 || *m > 10 || *m < 1 || *n < 1)
        return -1;
    return 0;
}

int arr_input(int array[][N], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &array[i][j]) != 1)
                return -1;
    return 0;
}

int summ_of_digits(int x)
{
    int sum = 0;
    if (x < 0)
        x *= -1;
    while (x > 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}

void line_offset(int array[][N], int **n, int *i, int m)
{
    **n += 1;
    for (int j = 0; j < m; j++)
        for (int k = **n - 1; k > *i - 1; k--)
            array[k][j] = array[k - 1][j];
    for (int j = 0; j < m; j++)
        array[*i][j] = -1;
    *i += 1;
    return;
}

void arr_check(int array[][N], int *n, int m)
{
    int quantity_of_numbers;
    int i = 0;
    while (i < *n)
    {
        quantity_of_numbers = 0;
        for (int j = 0; j < m; j++)
            if (summ_of_digits(array[i][j]) % 2 == 1)
                quantity_of_numbers++;
        if (quantity_of_numbers >= 2)
            line_offset(array, &n, &i, m);
        i++;
    }
    return;
}

void arr_print(int array[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    return;
}

int main()
{
    int n, m;
    if (size_input(&n, &m) != 0)
        return 1;
    int array[N][N];
    if (arr_input(array, n, m) != 0)
        return 1;
    arr_check(array, &n, m);
    arr_print(array, n, m);
    return 0;
}
