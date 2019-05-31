#include <stdio.h>
#include <string.h>

char *my_strpbrk(char *str11, char *str12)
{
    int i = 0;
    char *rc;
    int founded = 0;
    while (1)
    {
        if (str11[i] == '\0')
            break;
        int j = 0;
        founded = 0;
        while (1)
        {
            if (str12[j] == '\0')
                break;
            if (str11[i] == str12[j])
            {
                rc = &str11[i];
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

unsigned long int my_strspn(char *str21, char *str22)
{
    int i = 0;
    int j;
    unsigned long  int count = 0;
    while (1)
    {
        if (str21[i] == '\0')
            break;
        j = 0;
        while(1)
        {
            if (str22[j] == '\0')
            {
                return count;
                break;
            }
            if (str22[j] == str21[i])
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
    char str11[] = "esfoi-1 ueh .,10 ! ;";
    char str12[] = "2wef;.!-1 ";
    if (my_strpbrk(str11, str12) != strpbrk(str11, str12))
    {
        printf("my_strpbrk : FAILED, ожидалось: %s, фактическое: %s", strpbrk(str11, str12), my_strpbrk(str11, str12));
        return 1;
    }
    char str21[] = "20112 f-1-1p.,! tpa";
    char str22[] = "012f -1p.,!";
    if (my_strspn(str21, str22) != strspn(str21, str22))
    {
        printf("my_strspn : FAILED, ожидалось: %lu, фактическое: %lu", strspn(str21, str22), my_strspn(str21, str22));
        return 2;
    }
    return 0;
}
