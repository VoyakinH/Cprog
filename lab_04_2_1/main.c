#include <stdio.h>

void srar(int ok, double s)
{
    s = s / ok;
    printf("%lf\n", s);
    return;
}

int main(void)
{
    int n, i, rs, ok;
    double s;
    rs = scanf("%d", &n);
    if (rs != 1 || n > 10 || n <= 0)
        return 1;
    int array[n];
    ok = 0;
    for (i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1)
            return 1;
        if (array[i] < 0)
        {
            ok++;
            s += array[i];
        }
    }
    if (ok == 0)
        return 1;
    srar(ok, s);
    return 0;
}
