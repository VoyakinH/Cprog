#include <stdio.h>

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

int main()
{
    int n, i, kolpol, rs;
    rs = scanf("%d", &n);
    if (n <= 0 || n > 10 || rs != 1)
        return 1;
    int array[2 * n];
    kolpol = 0;
    rs = 0;
    for (i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1)
            return 1;
        if (array[i] > 0)
            kolpol = 1;
    }
    if (kolpol == 0)
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
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}
