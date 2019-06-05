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
    int r[N];
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
            r[i] = rand() % 101;
        wrote = fwrite(&r, sizeof(int), number, f);
        printf("Write %s\n", wrote == number ? "OK" : "ERROR");
        fclose(f);
        if (wrote != number)
            return -2;
    }
    fclose(f);
    return 0;
}

int print_file(char *name)
{
    FILE *f;
    int number;
    size_t read;
    setbuf(stdout, NULL);
    f = fopen(name, "rb");
    if (!f)
        return -1;
    read = fread(&number, sizeof(int), 1, f);
    if (feof(f))
    {
        fclose(f);
        return -4;
    }
    fseek(f, 0, SEEK_SET);
    while (1)
    {
        read = fread(&number, sizeof(int), 1, f);
        if (feof(f))
            break;
        if (read != 1)
        {
            printf("\n");
            fclose(f);
            return -3;
        }
        printf("%d ", number);
    }
    fclose(f);
    return 0;
}

int get_number_by_pos(FILE **f, int pos, int *err)
{
    int number;
    if (fseek(*f, pos, SEEK_SET) != 0)
        *err += 1;
    if (fread(&number, sizeof(int), 1, *f) != 1)
        *err += 1;
    return number;
}

void put_number_by_pos(FILE **f, int pos, int *err, int number)
{
    size_t wrote;
    if (fseek(*f, pos, SEEK_SET) != 0)
        *err += 1;
    wrote = fwrite(&number, sizeof(int), 1, *f);
    if (wrote != 1)
        *err += 1;
    return;
}

int sort_file(char *name)
{
    FILE *f;
    int err = 0;
    int x, y, rc;
    setbuf(stdout, NULL);
    f = fopen(name, "rb+");
    if (!f)
        return -1;
    rc = fseek(f, -sizeof(int), SEEK_END);
    int pos = ftell(f);
    if (rc != 0)
    {
        fclose(f);
        return -2;
    }
    for (int i = 0; i < pos; i += sizeof(int))
        for (int j = i + sizeof(int); j <= pos; j += sizeof(int))
        {
            x = get_number_by_pos(&f, i, &err);
            y = get_number_by_pos(&f, j, &err);
            if (err != 0)
            {
                fclose(f);
                return -3;
            }
            if (x > y)
            {
                put_number_by_pos(&f, i, &err, y);
                put_number_by_pos(&f, j, &err, x);
                if (err != 0)
                {
                    fclose(f);
                    return -4;
                }
            }
        }
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
            if (create_file(argv[2]) != 0)
                rc = -2;
        }
        else
        {
            if (strcmp(argv[1], "p") == 0)
            {
                if (print_file(argv[2]) != 0)
                    rc = -3;
            }
            else
            {
                if (strcmp(argv[1], "s") == 0)
                {
                    if (sort_file(argv[2]) != 0)
                        rc = -3;
                }
                else
                    rc = -5;
            }
        }
    }
    return rc;
}
