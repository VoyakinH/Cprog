#include <stdio.h>

int main()
{
    float r1, r2, r3;
    scanf("%f%f%f", &r1, &r2, &r3);
    r1 = 1 / r1;
    r1 += 1 / r2;
    r1 += 1 / r3;
    r1 = 1 / r1;
    printf("%f", r1);
    return 0;
}
