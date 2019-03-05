#include <stdio.h>

int main()
{
    float v1, t1, v2, t2, s;
    scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
    s = (v1 * t1 + v2 * t2) / (v1 + v2);
    printf("%f %f", v1 + v2, s);
    return 0;
}
