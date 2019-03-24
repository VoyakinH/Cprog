#include <stdio.h>

int swit(int j)
{
    int new = 0;
    while (j != 0)
    {
        if (new != 0)
            new *= 10;
        new += j % 10;
        j = j / 10;
    }
    return new;
}

void vstav(int array[], int n)
{
    int j;
    int i = 0;
    while (i < n)
    {
        if (array[i] > 0)
        {
            for ( j = n; j > i + 1; j--)
                array[j] = array[j - 1];
            j = array[i];
            array [i + 1] = swit(j);
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
    int array[2 * n];
    kolpol = 0;
    for (i = 0; i < n; i++)
    {
        rs += scanf("%d", &array[i]);
        if (array[i] > 0)
            kolpol++;
    }
    if (kolpol == 0 || rs != n + 1)
        return 1;
    vstav(array, n);
    return 0;
}


