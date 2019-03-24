#include <stdio.h>

void srar(int array[], int n, int rs2)
{
    double s = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
            s += array[i];
    s = s / rs2;
    printf("%lf\n", s);
}

int main(void)
{
    int n, i, rs1, rs2;
    scanf("%d", &n);
    int array[n];
    rs1 = 0;
    rs2 = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        if (array[i] < 0)
            rs2++;
    }
    srar(array, n, rs2);
    return 0;
}
