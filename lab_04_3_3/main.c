#include <stdio.h>

int swit(int rs)
{
    int kolpol = 0;
    while (rs != 0)
    {
        if (kolpol != 0)
            kolpol *= 10;
        kolpol += rs % 10;
        rs = rs / 10;
    }
    return kolpol;
}

void vstav(int array[], int n)
{
    int rs;
    int i = 0;
    while (i < n)
    {
        if (array[i] > 0)
        {
            for (rs = n; rs > i + 1; rs--)
                array[rs] = array[rs - 1];
            rs = array[i];
            array [i + 1] = swit(rs);
            n++;
            i++;
        }
        i++;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    return;
}

int main(void)
{
    int n, i, kolpol, rs;
    rs = scanf("%d", &n);
    if (n == 0)
        return 1;
    if (rs != 1 || rs == EOF)
        return 1;
    int array[2 * n];
    kolpol = 0;
    for (i = 0; i < n; i++)
    {
        rs += scanf("%d", &array[i]);
        if (array[i] > 0)
            kolpol++;
    }
    if (kolpol == 0 || rs != n + 1 || rs == EOF)
        return 1;
    vstav(array, n);
    return 0;
}


