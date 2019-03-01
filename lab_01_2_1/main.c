#include <stdio.h>
#include <math.h>

int main(void)
{
    float x1, y1, x2, y2, x3, y3, s;
    scanf("%f%f%f%f%f%f" , &x1, &y1, &x2, &y2, &x3, &y3);
    s = 0;
    s += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    s += sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    s += sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    printf("%.5f", s);
    return 0;
}
