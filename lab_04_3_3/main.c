#include <stdio.h>

int main(void)
{
    int n, i, kolpol, rs, j;
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
        if (array[i] > 0)
        {
            for (rs = n; rs > i + 1; rs--)
                array[rs] = array[rs - 1];
            kolpol = 0;
            j = array[i];
            while (j != 0)
            {
                if (kolpol != 0)
                    kolpol *= 10;
                kolpol += j % 10;
                j = j / 10;
            }
            array[i + 1] = kolpol;
            n++;
            i++;
        }
        i++;
    }
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}
