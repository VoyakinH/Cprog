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
            kolpol++;
        if (rs != 1 || rs == EOF)
            return -1;
    }
    if (kolpol == 0)
        return -1;
    return 1;
}

void sdvig(int array[], int n, int i, int x)
{
    for (int rs = n; rs > i + 1; rs--)
        array[rs] = array[rs - 1];
    array[i + 1] = x;
    return;
}

int reverse(int array[], int i)
{
    int kolpol = 0;
    int j = array[i];
    while (j != 0)
    {
        if (kolpol != 0)
            kolpol *= 10;
        kolpol += j % 10;
        j = j / 10;
    }
    return kolpol;
}

void arr_output(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    return;
}

int main()
{
    int n, i, rs;
    n = n_input();
    if (n == -1)
        return 1;
    int array[n * 2];
    rs = arr_input(n, array);
    if (rs == -1)
        return 1;
    i = 0;
    while (i < n)
    {
        if (array[i] > 0)
        {
            sdvig(array, n, i, reverse(array, i));
            i++;
            n++;
        }
        i++;
    }
    arr_output(array, n);
    return 0;
}
