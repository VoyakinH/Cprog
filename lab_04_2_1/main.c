#include <stdio.h>

double srar(int array[], int n)
{
    double s = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
        {
            s += array[i];
            k++;
        }
    if (k == 0)
        return 1;
    s = s / k;
    return s;
}
int main(void)
{
    int n, i, rs1, rs2, rs3;
    double s;
    char tmp;
    rs2 = scanf("%d", &n);
    if (rs2 != 1 || rs2 == EOF)
        return 1;
    int array[n];
    rs1 = 0;
    for (i = 0; i < n; i++)
        rs1 += scanf("%d", &array[i]);
    rs3 = scanf("%c", &tmp);
    if (rs3 != 1 || rs3 == EOF)
        return 1;
    if (rs1 != n || (tmp != '\n' && tmp != ' ' && tmp != '\r'))
        return 1;
    s = srar(array, n);
    if (s == 1)
        return 1;
    printf("%lf", s);
    return 0;
}

