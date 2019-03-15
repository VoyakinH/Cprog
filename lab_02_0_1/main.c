#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, n, rc, s;
    rc = scanf("%d %d", &a, &n);
    s = 1;
    if (rc == 2 && n > 0)
    {
        for (int i = 1; i <= n; i++)
            s *= a;
        printf("%d", s);
        return 0;
    }
    else
    {
        printf("Input error");
        return 1;
    }
}
