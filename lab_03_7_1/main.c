#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process(FILE* fsrc, int *k)
{
    int x, y, z, num;
    num = 0;
    if (fscanf(fsrc, "%d", &x) != 1)
        return -1;
    if (fscanf(fsrc, "%d", &y) != 1)
        return -1;
    while (1)
    {
        if (fscanf(fsrc, "%d", &z) != 1)
            break;
        if (y > x && y > z)
            num++;
        x = y;
        y = z;
        if (feof(fsrc))
            break;
    }
    *k = num;
    return 0;
}

int main(void)
{
    int k = 0;
    FILE *fsrc;
    fsrc = stdin;
    if (process(fsrc, &k) == -1)
    {
        printf("Not enough numbers\n");
        fclose(fsrc);
        return -1;
    }
    printf("%d\n", k);
    fclose(fsrc);
    return 0;
}
