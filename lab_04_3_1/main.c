#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, ls;
    float s, k;
    scanf("%d", &n);
    if (n < 0 || n > 10)
        return 1;
    int array[n];
    ls = 0;
    for (i = 0; i < n; i++)
        ls += scanf("%d", &array[i]);
    if (ls != n)
        return 1;
    s = 1;
    k = 0;
    for (i = 0; i < n; i++)
        if (array[i] > 0)
        {
            s *= array[i];
            k++;
        }
    if (k == 0 )
        return 1;
    k = 1 / k;
    s = pow(s, k);
    printf("%.6f", s);
    return 0;
}
