#include <stdio.h>

int srar(int array[], int n)
{
    int k = 0;
    float s = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
        {
            k++;
            s += array[i];
        }
    if (k == 0)
        return 1;
    s /= k;
    printf("%.6f", s);
    return 0;
}

int main(void)
{
    int n, i, rs;
    rs = scanf("%d", &n);
    if (rs != 1 || n > 10 || n <= 0)
        return 1;
    int array[n];
    for (i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1)
            return 1;
    }
    rs = srar(array, n);
    if (rs == 1)
        return 1;
    return 0;
}
