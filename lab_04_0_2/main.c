#include <stdio.h>

int n_input()
{
    int rs, n;
    rs = scanf("%d", &n);
    if (rs != 1 || n > 10 || n <= 0)
        return -1;
    return n;
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
    return 1;
}

int new_array(int array[], int n, int array1[])
{
    int i;
    float s = 0;
    for (int i = 0; i < n; i++)
        s += array[i];
    s /= n;
    int k = 0;
    for (i = 0; i < n; i++)
        if (array[i] > s)
        {
            array1[k] = array[i];
            k++;
        }
    if (k == 0)
        return 1;
    return 0;
}

void arr_output(int array1[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array1[i]);
    return;
}

int main(void)
{
    int n, rs;
    n = n_input();
    if (n == -1)
        return 1;
    int array[n];
    rs = arr_input(n, array);
    if (rs == -1)
        return 1;
    int array1[n];
    rs = new_array(array, n, array1);
    if (rs == 1)
        return 1;
    arr_output(array1, n);
    return 0;
}
