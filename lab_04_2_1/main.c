#include <stdio.h>

int n_input(int *n)
{
    int rs;
    rs = scanf("%d", &*n);
    if (rs != 1 || *n > 10 || *n <= 0)
        return -1;
    return 0;
}

int arr_input(int n, int array[])
{
    int rs;
    for (int i = 0; i < n; i++)
    {
        rs = scanf("%d", &array[i]);
        if (rs != 1 || rs == EOF)
            return -1;
    }
    return 0;
}

int srar(int array[], int n, float *s)
{
    int k = 0;
    *s = 0;
    for (int i = 0; i < n; i++)
        if (array[i] < 0)
        {
            k++;
            *s += array[i];
        }
    if (k == 0)
        return -1;
    *s /= k;
    return 0;
}

void output(float s)
{
    printf("%.6f\n", s);
    return;
}

int main()
{
    int n;
    float s;
    if (n_input(&n) == -1)
        return 1;
    int array[n];
    if (arr_input(n, array) == -1)
        return 1;
    if (srar(array, n, &s) == -1)
        return 1;
    output(s);
    return 0;
}
