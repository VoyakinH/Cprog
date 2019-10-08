#include <stdio.h>
#include <inttypes.h>

void fill(int64_t ***res_p, int64_t ***a_p, int n, int ro)
{
    int i = 0, j = 0;
    if (ro != 0)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                (*res_p)[i][j] = (*a_p)[i][j];
    else
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    (*res_p)[i][j] = 1;
                else
                    (*res_p)[i][j] = 0;
            }
    return;
}

int64_t find_element(int64_t ***res_p, int64_t ***a_p, int n, int x, int y)
{
    int i = 0;
    int64_t s = 0;
    for (i = 0; i < n; i++)
        s += (*res_p)[x][i] * (*a_p)[i][y];
    return s;
}

void multiply(int64_t ***res_p, int64_t ***a_p, int n)
{
    int i = 0, j = 0;
    int64_t buff[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            buff[i][j] = find_element(res_p, a_p, n, i, j);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            (*res_p)[i][j] = buff[i][j];
    return;
}

void count_result(int64_t ***a_p, int64_t ***b_p, int64_t ***res_p, int n, int ro, int nu)
{
    int i = 0;
    for (i = 0; i < ro - 1; i++)
        multiply(res_p, a_p, n);
    for (i = 0; i < nu; i++)
        multiply(res_p, b_p, n);
    return;
}
