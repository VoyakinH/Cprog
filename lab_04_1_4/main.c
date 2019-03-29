#include <stdio.h>

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
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    return;
}

int main(void)
{
    int i, n, rs;
    rs = scanf("%d", &n);
    if (rs != 1 || rs == EOF || n <= 0 || n > 10)
        return 1;
    int array[n];
    for (i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1 || rs == EOF)
            return 1;
    }
    sort(array, n);
    return 0;
}
