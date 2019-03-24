#include <stdio.h>

int new_array(int array[], int n)
{
    int array1[n];
    int i;
    float s = 0;
    for (int i = 0; i < n; i++)
        s += array[i];
    s /= n;
    int k = 0;
    for (i  = 0; i < n; i++)
        if (array[i] > s)
        {
            array1[k] = array[i];
            k++;
        }
    if (k == 0)
        return 1;
    for (i = 0; i < k; i++)
        printf("%d", array1[i]);
    return 0;
}

int main(void)
{
    int n, i, j, rs;
    scanf("%d", &n);
    int array[n];
    rs = 0;
    for (i = 0; i < n; i++)
        rs += scanf("%d", &array[i]);
    if (rs != n || rs == EOF)
        return 1;
    j = new_array(array,  n);
    if (j == 1)
        return 1;
    return 0;
}
