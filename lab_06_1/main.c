#include <stdio.h>
#include <string.h>

char *my_strpbrk(char *str1, char *str2)
{
    int i = 0;
    char *rc;
    int founded = 0;
    while (1)
    {
        if (str1[i] == '\0')
            break;
        int j = 0;
        founded = 0;
        while (1)
        {
            if (str2[j] == '\0')
                break;
            if (str1[i] == str2[j])
            {
                rc = &str1[i];
                founded = 1;
                break;
            }
            j++;
        }
        if (founded == 1)
            break;
        i++;
    }
    if (founded == 0)
        rc = NULL;
    return rc;
}

unsigned long int my_strspn(char *str1, char *str2)
{
    int i = 0;
    int j;
    unsigned long  int count = 0;
    while (1)
    {
        if (str1[i] == '\0')
            break;
        j = 0;
        while(1)
        {
            if (str2[j] == '\0')
            {
                return count;
                break;
            }
            if (str2[j] == str1[i])
            {
                count++;
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}


int main()
{
    char str1[] = "201201 oqkdj";
    char str2[] = "210";
    if (my_strpbrk(str1, str2) != strpbrk(str1, str2))
    {
        printf("my_strpbrk : FAILED, ожидалось: %s, фактическое: %s", strpbrk(str1, str2), my_strpbrk(str1, str2));
        return 1;
    }
    if (my_strspn(str1, str2) != strspn(str1, str2))
    {
        printf("my_strspn : FAILED, ожидалось: %lu, фактическое: %lu", strspn(str1, str2), my_strspn(str1, str2));
        return 2;
    }
    return 0;
}
