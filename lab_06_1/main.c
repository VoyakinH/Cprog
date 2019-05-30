#include <stdio.h>
#include <string.h>
#define N 100

void read_str(char *str1, char *str2)
{
    gets(str1);
    gets(str2);
}

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


int main(void)
{
    char *actual;
    char *expected;
    char str1[N], str2[N];
    read_str(str1, str2);
    actual = my_strpbrk(str1, str2);
    expected = strpbrk(str1, str2);
    if (actual != expected)
    {
        printf("my_strpbrk : FAILED, ожидалось: %s, фактическое: %s", expected, actual);
        return 1;
    }
    return 0;
}
