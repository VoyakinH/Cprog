#include <stdio.h>
#include <string.h>
#define N 258
#define K 17

void get_str(char *str1)
{
    FILE *f;
    f = stdin;
    fgets(str1, N, f);
    return;
}

int split_str(char *str1, char str1_words[N][K])
{
    int str1_i = 0;
    char x = 'c';
    int if_ch = 0;
    int words_i = 0;
    int el_i = 0;
    while (str1[str1_i] != '\n')
    {
        x = str1[str1_i];
        if (x != ' ' && x != ',' && x != ';' && x != ':' && x != '-' && x != '.' && x != '!' && x != '?')
        {
            str1_words[words_i][el_i] = x;
            el_i++;
            if_ch = 1;
            if (str1[str1_i + 1] == '\n')
            {
                str1_words[words_i][el_i] = '\0';
                words_i++;
            }
        }
        else
        {
            if (if_ch)
            {
                str1_words[words_i][el_i] = '\0';
                el_i = 0;
                if_ch = 0;
                words_i++;
            }
        }
        str1_i++;
    }
    return words_i;
}

void remove_duplicates(char str1_words[N][K], int *n1)
{
    if (*n1 == 1)
        return;
    int i, j;
    int pos = *n1 - 1;
    while (pos > 0)
    {
        for (i = pos - 1; i >= 0; i--)
        {
            if (strcmp(str1_words[pos], str1_words[i]) == 0)
            {
                if (pos != *n1 - 1)
                {
                    for (j = pos; j < *n1 - 1; j++)
                        strcpy(str1_words[j], str1_words[j + 1]);
                    *n1 -= 1;
                }
                else
                    *n1 -= 1;
                break;
            }
        }
        pos--;
    }
    
    return;
}

void print_without_check(char str1_words[N][K], int n1)
{
    for (int i = 0; i < n1; i++)
        printf("Result: %s no\n", str1_words[i]);
    return;
}

void check(char str1_words[N][K], char str2_words[N][K], int n1, int n2)
{
    int founded = 1;
    for (int i = 0; i < n1; i++)
    {
        founded = 1;
        for (int j = 0; j < n2; j++)
        {
            if (strcmp(str1_words[i], str2_words[j]) == 0)
            {
                printf("Result: %s yes\n", str1_words[i]);
                founded = 0;
                break;
            }
        }
        if (founded)
            printf("Result: %s no\n", str1_words[i]);
    }
    return;
}

int main()
{
    char str1[N] = { 0 };
    get_str(str1);
    int n1 = 0;
    int n2 = 0;
    int len = strlen(str1);
    if (len > 0)
    {
        if (str1[len - 1] != '\n')
            return -1;
    }
    else
        return -6;
    if (len == 1)
        return -2;
    char str1_words[N][K] = { 0 };
    n1 = split_str(str1, str1_words);
    if (n1 == 0)
        return -3;
    remove_duplicates(str1_words, &n1);
    char str2[N] = { 0 };
    get_str(str2);
    len = strlen(str2);
    if (len > 0)
    {
        if (str2[len - 1] != '\n')
            return -4;
    }
    else
        return -5;
    len = strlen(str2);
    if (len == 1)
        print_without_check(str1_words, n1);
    else
    {
        char str2_words[N][K] = { 0 };
        n2 = split_str(str2, str2_words);
        if (n2 == 0)
            print_without_check(str1_words, n1);
        else
            check(str1_words, str2_words, n1, n2);
    }
    return 0;
}
