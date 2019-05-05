#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int kol_ch(FILE* fsrc, int *n)
{
    int k = 0;
    float x;
    while (1)
    {
        if (fscanf(fsrc, "%f", &x) != 1)
        {
            if (k == 0)
                return -1;
            break;
        }
        k++;
        if (feof(fsrc))
            break;
    }
    if (k == 1)
        return -1;
    *n = k;
    return 0;
}

void mat_oj(FILE* fsrc, int n, float *M)
{
    float x;
    float M_buf = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(fsrc, "%f", &x);
        M_buf += x / n;
    }
    *M = M_buf;
    return;
}

void disp(FILE* fsrc, int n, float M, float *D)
{
    float x;
    float D_buf = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(fsrc, "%f", &x);
        D_buf += ((x - M) * (x - M) / (n - 1));
    }
    *D = sqrt(D_buf);
    return;
}

void out(float D)
{
    printf("%.6f", D);
    return;
}

int main(int argc, char** argv)
{
    int n = 0;
    int rc = 0;
    float M = 0;
    float D = 0;
    FILE *fsrc;
    if (argc != 2)
        rc = -1;
    else
    {
        fsrc = fopen(argv[1], "r");
        if (fsrc)
        {
            if (kol_ch(fsrc, &n) == 0)
            {
                rewind(fsrc);
                mat_oj(fsrc, n, &M);
                rewind(fsrc);
                disp(fsrc, n, M, &D);
                out(D);
            }
            else
            {
                fprintf(stderr, "Could not read numbers in %s because of %s\n or there is only one number", argv[1], strerror(errno));
                rc = -3;
            }
        }
        else
        {
            fprintf(stderr, "Could not open %s because of %s\n", argv[1], strerror(errno));
            rc = -2;
        }
    }
    if (rc != -1 && rc != -2)
        fclose(fsrc);
    return rc;
}
