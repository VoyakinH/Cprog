#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process(file *fsrc, int *k)
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
    file *fsrc;
    int k = 0;
    fsrc = fopen("f.txt", "r");
    if (!fsrc)
    {
        printf("Could not open f.txt\n");
        return -1;
    }
    if (process(fsrc, &k) == -1)
    {
        printf("Not enough numbers in f.txt\n");
        fclose(fsrc);
        return -2;
    }
    printf("%d\n", k);
    fclose(fsrc);
    return 0;
}
