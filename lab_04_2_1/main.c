#include <stdio.h>

float srar(int array[], int n)
{
    int s = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
        {
            s += array[i];
            k++;
        }
    if (k == 0)
        return 1;
    s = s / k;
    return s;
}
int main(void)
{
    int n, i, rs, k;
    float s;
    char tmp;
    scanf("%d", &n);
    int array[n];
    rs = 0;
    for (i = 0; i < n; i++)
        rs += scanf("%d", &array[i]);
    scanf("%c", &tmp);
    if (rs != n || (tmp != '\n' && tmp != ' '))
        return 1;
    s = srar(array, n);
    if (s == 1)
        return 1;
    printf("%f", s);
    return 0;
}
