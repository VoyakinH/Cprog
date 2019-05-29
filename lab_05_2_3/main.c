#include <stdio.h>
#define N 10

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
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (scanf("%d", &array[i][j]) != 1)
                return -1;
    return 0;
}

void sort(int array[][N], int n, int m)
{
    int pointer_1, pointer_2, j, comp_1, comp_2, buff;
    for (pointer_1 = 0; pointer_1 < n - 1; pointer_1++)
    {
        for (pointer_2 = pointer_1 + 1; pointer_2 < n; pointer_2++)
        {
            comp_1 = 1;
            for (j = 0; j < m; j++)
                comp_1 *= array[pointer_1][j];
            comp_2 = 1;
            for (j = 0; j < m; j++)
                comp_2 *= array[pointer_2][j];
            if (comp_1 > comp_2)
                for (j = 0; j < m; j++)
                {
                    buff = array[pointer_1][j];
                    array[pointer_1][j] = array[pointer_2][j];
                    array[pointer_2][j] = buff;
                }
        }
    }
    return;
}

void arr_print(int array[][N], int n, int m)
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
    int n, m;
    if (size_input(&n, &m) != 0)
        return 1;
    int array[N][N];
    if (arr_input(array, n, m) != 0)
        return 1;
    sort(array, n, m);
    arr_print(array, n, m);
    return 0;
}
