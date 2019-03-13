#include <stdio.h>
#include <math.h>

float fun(float x)
{
    return asin(x);
}

float elem(float i, float x)
{
    int j = 2 * i - 1;
    float ele = 1;
    for (int k = 1; k < j; k += 2)
        ele *= k;
    ele *= pow(x, j);
    for (int k = 2; k < j; k += 2)
        ele /= k;
    ele /= j;
    return ele;
}


int main(void)
{
    float eps, s, x;
    int st;
    st = scanf("%f%f", &x, &eps);
    if (st == 2 && x <= 1 && x >= -1 && eps > 0 && eps < 1)
    {
        float f = fun(x);
        s = 0;
        int i = 2;
        float chlen = x;
        while (fabs(chlen) > eps)
        {
            s += chlen;
            chlen = elem(i, x);
            i++;
        }
        printf("%.6f %.6f %.6f %.6f", s, f, fabs(f - s), fabs((f - s) / f));
    }
    else
    {
        printf("Input error");
        return 1;
    }
}
