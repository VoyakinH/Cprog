#include <stdio.h>

void srar(int array[], int n)
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
        {
            s += array[i];
            k++;
        }
    s = s / k;
    printf("%lf", s);
}

int main(void)
{
    int n, i, rs1;
    scanf("%d", &n);
    int array[n];
    rs1 = 0;
    for (i = 0; i < n; i++)
        rs1 += scanf("%d", &array[i]);
    if (rs1 != n)
        return 1;
    srar(array, n);
    return 0;
}

