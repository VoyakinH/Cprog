#include <stdio.h>
#include <string.h>
#include "my_snprintf.h"

static int output_data(const int count, const int required_count, const char *name)
{
    int result = 0;
    printf("%s: ", name);
    if (count == required_count)
        printf("OK\n");
    printf("Tests passed %d of %d\n\n", count, required_count);
    if (count == required_count)
        result++;
    return result;
}

static int system_16_work_corr()
{
    char expected[7] = { 'A', 'B', 'C', 'D', 'E', 'F', '0' };
    int input[7] = { 10, 11, 12, 13, 14, 15, 9 };
    int count = 0;

    for (int i = 0; i < 7; i++)
        if (system_16(input[i]) == expected[i])
            count++;

    return output_data(count, 7, "system_16");
}

static int int_to_str_work_corr()
{
    char expected[3][4] = { { "-10" }, { "123" }, { "0" } };
    int input[3] = { -10, 123, 0 };
    char actual[4];
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        int_to_str(input[i], actual);
        if (strcmp(actual, expected[i]) == 0)
            count++;
    }

    return output_data(count, 3, "int_to_str");
}

static int count_len_str_work_corr()
{
    int expected[4] = { 3, 3, 1, 0 };
    char input[4][4] = { { "-10" }, { "hi\n" }, { "0" }, { "" } };
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        if (expected[i] == count_len_str(input[i]))
            count++;
    }

    return output_data(count, 4, "count_len_str");
}

static int out_string_work_corr()
{
    char expected[4][4] = { { "-10" }, { "hi" }, { "0" }, { "" } };
    char input[4][4] = { { "-10" }, { "hi\n" }, { "0" }, { "" } };
    int buff_size[4] = { 4, 3, 5, 1 };
    int pos = 0;
    char buffer[10];
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        pos = 0;
        out_string(buffer, buff_size[i], &pos, input[i]);
        buffer[pos] = '\0';
        if (strcmp(buffer, expected[i]) == 0)
            count++;
    }

    return output_data(count, 4, "out_string");
}

static int convert_num_sys_work_corr()
{
    char expected[4][4] = { { "7B" }, { "0" }, { "3DF" }, { "64" } };
    unsigned short input[4] = { 123, 0, 991, 100 };
    char buffer[10];
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        convert_num_sys(input[i], buffer);
        if (strcmp(buffer, expected[i]) == 0)
            count++;
    }

    return output_data(count, 4, "convert_num_sys");
}

static int my_snprintf_work_corr()
{
    char expected[4][20] = { { "hiq 10q Aq" }, { "hellq 999q 3E7q" }, { "key\nq -10q 28q" }, { "hehq 0q 0q" } };
    int expected_count[4] = { 10, 15, 14, 10 };
    char input_str[4][5] = { { "hi" }, { "hell" }, { "key\n" }, { "heh" } };
    int input_int[4] = { 10, 999, -10, -0 };
    unsigned short input_16[4] = { 10, 999, 40, 0 };
    char buffer[20];

    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        if (my_snprintf(buffer, 20, "%sq %iq %hXq", input_str[i], input_int[i], input_16[i]) == expected_count[i] && strcmp(buffer, expected[i]) == 0)
            count++;
    }

    if (my_snprintf(NULL, 1, "123") == -1)
        count++;
    if (my_snprintf(buffer, 2, "%%") == 1 && strcmp(buffer, "%") == 0)
        count++;
    if (my_snprintf(buffer, 3, "123") == 3 && strcmp(buffer, "12") == 0)
        count++;
    if (my_snprintf(buffer, 2, "%hhY") == 1 && strcmp(buffer, "Y") == 0)
        count++;

    return output_data(count, 8, "my_snprintf");
}

int main()
{
    int count = 0;
    count += system_16_work_corr();
    count += int_to_str_work_corr();
    count += count_len_str_work_corr();
    count += out_string_work_corr();
    count += convert_num_sys_work_corr();
    count += my_snprintf_work_corr();

    printf("Test functions passed %d of 6\n", count);

    return 0;
}
