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

void mat_oj(FILE* fsrc, int n, float *m)
{
    float x;
    float m_buf = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(fsrc, "%f", &x);
        m_buf += x / n;
    }
    *m = m_buf;
    return;
}

void disp(FILE* fsrc, int n, float m, float *d)
{
    float x;
    float d_buf = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(fsrc, "%f", &x);
        d_buf += ((x - m) * (x - m) / (n - 1));
    }
    d_buf = sqrt(d_buf);
    *d = d_buf;
    return;
}

void out(float d, float m)
{
    printf("%f", m, d);
    return;
}

int main(int argc, char **argv)
{
    int n = 0;
    int rc = 0;
    float m = 0;
    float d = 0;
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
                mat_oj(fsrc, n, &m);
                rewind(fsrc);
                disp(fsrc, n, m, &d);
                out(d, m);
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
