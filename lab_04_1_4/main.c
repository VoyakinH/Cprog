#include <stdio.h>

int n_input()
{
    int rs, n;
    rs = scanf("%d", &n);
    if (rs != 1 || n > 10 || n <= 0)
        return -1;
    return n;
}

int arr_input(int n, int array[])
{
    int rs;
    int kolpol = 0;
    for (int i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (array[i] > 0)
            kolpol = 1;
        if (rs != 1 || rs == EOF)
            return -1;
    }
    if (kolpol == 0)
        return -1;
    return 1;
}

void sort(int array[], int n)
{
    int i, x, j;
    for (i = 1; i < n; i++)
    {
        x = array[i];
        j = i;
        while (j > 0 && array[j - 1] > x)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = x;
    }
    return;
}

void arr_output(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    return;
}

int main(void)
{
    int n, rs;
    n = n_input();
    if (n == -1)
        return 1;
    int array[n];
    rs = arr_input(n, array);
    if (rs == -1)
        return 1;
    sort(array, n);
    arr_output(array, n);
    return 0;
}
