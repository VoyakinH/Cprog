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
        founded = 0;
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
    unsigned long int count = 0;
    while (1)
    {
        if (str21[i] == '\0')
            break;
        j = 0;
        while (1)
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

unsigned long int my_strcspn(char *str31, char *str32)
{
    int i = 0;
    int j;
    unsigned long int count = 0;
    while (1)
    {
        if (str31[i] == '\0')
            break;
        j = 0;
        while (1)
        {
            if (str32[j] == '\0')
            {
                count++;
                break;
            }
            if (str32[j] == str31[i])
            {
                return count;
                break;
            }
            j++;
        }
        i++;
    }
    return count;
}

char *my_strchr(const char *str41, const int ch_4)
{
    if (ch_4 > 255 || ch_4 < 0)
        return NULL;
    char *rc;
    int i = 0;
    while (1)
    {
        if (str41[i] == '\0')
            break;
        if (str41[i] == (char)ch_4)
        {
            rc = (char *)&str41[i];
            return rc;
        }
        i++;
    }
    rc = NULL;
    return rc;
}

char *my_strrchr(const char *str51, const int ch_5)
{
    if (ch_5 > 255 || ch_5 < 0)
        return NULL;
    char *rc;
    int i = 0;
    int founded = 0;
    while (1)
    {
        if (str51[i] == '\0')
            break;
        if (str51[i] == (char)ch_5)
        {
            rc = (char *)&str51[i];
            founded = 1;
        }
        i++;
    }
    if (founded == 0)
        rc = NULL;
    return rc;
}

int main()
{
    char str11[] = "abcd aowpf ";
    char str12[] = "c w";
    char *actual_1 = my_strpbrk(str11, str12);
    char *expected_1 = strpbrk(str11, str12);
    if (actual_1 != expected_1)
    {
        printf("my_strpbrk : FAILED, ожидалось: %s, фактическое: %s", expected_1, actual_1);
        return 1;
    }
    char str21[] = "20112ef012";
    char str22[] = "012f";
    unsigned long int actual_2 = my_strspn(str21, str22);
    unsigned long int expected_2 = strspn(str21, str22);
    if (actual_2 != expected_2)
    {
        printf("my_strspn : FAILED, ожидалось: %lu, фактическое: %lu", expected_2, actual_2);
        return 2;
    }
    char str31[] = "20112ef3012f";
    char str32[] = "e3";
    unsigned long int actual_3 = my_strcspn(str31, str32);
    unsigned long int expected_3 = strcspn(str31, str32);
    if (actual_3 != expected_3)
    {
        printf("my_strspn : FAILED, ожидалось: %lu, фактическое: %lu", expected_3, actual_3);
        return 3;
    }
    char str41[] = "0123546789352";
    int ch_4 = '5';
    char *actual_4 = my_strchr(str41, ch_4);
    char *expected_4 = strchr(str41, ch_4);
    if (actual_4 != expected_4)
    {
        printf("my_strchr : FAILED, ожидалось: %s, фактическое: %s", expected_4, actual_4);
        return 4;
    }
    char str51[] = "0123546789352";
    int ch_5 = '5';
    char *actual_5 = my_strrchr(str51, ch_5);
    char *expected_5 = strrchr(str51, ch_5);
    if (actual_5 != expected_5)
    {
        printf("my_strrchr : FAILED, ожидалось: %s, фактическое: %s", expected_5, actual_5);
        return 5;
    }
    return 0;
}
