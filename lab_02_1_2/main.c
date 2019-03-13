#include <stdio.h>
#include <math.h>

int main(void)
{
    float rc, a, b, c, p, s;
    int x1, x2, x3, y1, y2, y3;
    rc = scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (rc == 6)
    {
        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%.6f", s);
        return 0;
    }
    else
    {
        printf("Input error");
        return 1;
    }
}
