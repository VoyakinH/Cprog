#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int process(FILE *fsrc, int *k)
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
    FILE *fsrc;
    int k = 0;
    fsrc = fopen("text.txt", "r");
    if (!fsrc)
    {
        printf("Could not open text.txt\n");
        return -1;
    }
    if (process(fsrc, &k) == -1)
    {
        printf("Not enough numbers in text.txt\n");
        return -2;
    }
    printf("%d", k);
    return 0;
}
