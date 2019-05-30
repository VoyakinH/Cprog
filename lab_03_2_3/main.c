/*
 Числа целые.
 Сортировка пузырьком.
 Сортировка по возростанию.
 Максимально кол-во чисел в бинарном файле = 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define N 100


int create_file(char *name)
{
    FILE *f;
    int  r[N];
    setbuf(stdout, NULL);
    int number;
    size_t wrote;
    f = fopen(name, "wb");
    if (!f)
        return -1;
    srand(42);
    printf("Input count of numbers: ");
    if (scanf("%d", &number) == 1 && number >= 0 && number <= 100)
    {
        for (int i = 0; i < number; i++)
            r[i] = rand();
        wrote = fwrite(&r, sizeof(int), number, f);
        printf("Write %s\n", wrote == number ? "OK" : "ERROR");
        fclose(f);
        if (wrote != number)
            return -2;
    }
    fclose(f);
    return 0;
}


int main(int argc, char **argv)
{
    int rc = 0;
    if (argc != 3)
        rc = -1;
    else
    {
        if (strcmp(argv[1], "c") == 0)
        {
            if(create_file(argv[2]) != 0)
                rc = -2;
        }
        else
        {
            if (strcmp(argv[1], "p") == 0)
            {
                ///
            }
            else
            {
                if (strcmp(argv[1], "s") == 0)
                {
                    ///
                }
                else
                    rc = -5;
            }
        }
    }
    return rc;
}
