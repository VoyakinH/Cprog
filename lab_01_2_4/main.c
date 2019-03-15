#include <stdio.h>
int main()
{
    int t, h, m, c;
    scanf("%d", &t);
    h = 0;
    m = 0;
    c = 0;
    c = t % 60;
    t = t / 60;
    m = t % 60;
    t = t / 60;
    h = t;
    printf("%d %d %d", h, m, c);
    return 0;
}
