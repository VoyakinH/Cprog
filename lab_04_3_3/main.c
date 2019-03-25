#include <stdio.h>

void vstav(int array[], int n)
{
    int rs, kolpol;
    int i = 0;
    while (i < n)
    {
        if (array[i] > 0)
        {
            for (rs = n; rs > i + 1; rs--)
                array[rs] = array[rs - 1];
            rs = array[i];
            kolpol = 0;
            while (rs != 0)
            {
                if (kolpol != 0)
                    kolpol *= 10;
                kolpol += rs % 10;
                rs = rs / 10;
            }
            array [i + 1] = kolpol;
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
    scanf("%d", &n);
    if (n <= 0 || n > 10)
        return 1;
    int array[2 * n];
    kolpol = 0;
    rs = 0;
    for (i = 0; i < n; i++)
    {
        rs += scanf("%d", &array[i]);
        if (array[i] > 0)
            kolpol++;
    }
    if (kolpol == 0 || rs != n || rs == EOF)
        return 1;
    vstav(array, n);
    return 0;
}


