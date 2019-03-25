#include <stdio.h>

void sdvig(int array[], int n, int i)
{
    for (int rs = n; rs > i + 1; rs--)
        array[rs] = array[rs - 1];
    return;
}

void reverse(int array[], int i)
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
    array[i + 1] = kolpol;
    return;
}

int main(void)
{
    int n, i, kolpol, rs;
    scanf("%d", &n);
    if (n <= 0 || n > 10)
        return 1;
    int array[n];
    kolpol = 0;
    rs = 0;
    for (i = 0; i < n; i++)
    {
        rs += scanf("%d", &array[i]);
        if (array[i] > 0)
            kolpol = 1;
    }
    if (kolpol == 0 || rs != n || rs == EOF)
        return 1;
    i = 0;
    while (i < n)
    {
        printf("%d ", array[i]);
        if (array[i] > 0)
        {
            sdvig(array, n, i);
            reverse(array, i);
            i++;
            n++;
            printf("%d ", array[i]);
        }
        i++;
    }
    return 0;
}
