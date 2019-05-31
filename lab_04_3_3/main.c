#include <stdio.h>

int n_input(int *n)
{
    if (scanf("%d", &*n) != 1)
        return -1;
    if (*n > 10 || *n <= 0)
        return -1;
    return 0;
}

int arr_input(int n, int array[])
{
    int rs;
    for (int i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1 || rs == EOF)
            return -1;
    }
    return 0;
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

void runner(int array[], int *n)
{
    int i = 0;
    while (i < *n)
    {
        if (array[i] > 0)
        {
            sdvig(array, *n, i, reverse(array, i));
            i++;
            *n += 1;
        }
        i++;
    }
    return;
}

void arr_output(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return;
}

int main()
{
    int n;
    if (n_input(&n) == -1)
        return 1;
    int array[n * 2];
    if (arr_input(n, array) == -1)
        return 1;
    runner(array, &n);
    arr_output(array, n);
    return 0;
}
