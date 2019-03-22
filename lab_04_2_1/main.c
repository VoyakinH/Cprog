#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, rs, k;
    float s;
    char tmp;
    scanf("%d", &n);
    if (n < 0 || n > 10)
        return 1;
    int array[n];
    rs = 0;
    for (i = 0; i < n; i++)
        rs += scanf("%d", &array[i]);
    scanf("%c", &tmp);
    if (rs != n || tmp != '\n')
        return 1;
    k = 0;
    s = 0;
    for (i = 0; i < n; i++)
        if (array[i] < 0)
        {
            s += array[i];
            k++;
        }
    if (k == 0)
        return 1;
    s = s / k;
    printf("%.6f\n", s);
    return 0;
}
