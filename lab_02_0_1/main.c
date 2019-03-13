#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, n, rc;
    rc = scanf("%d %d", &a, &n);
    if (rc == 2 && n > 0)
        printf("%.6f", pow(a, n));
    else
        printf("Input error");
    return 0;
}
