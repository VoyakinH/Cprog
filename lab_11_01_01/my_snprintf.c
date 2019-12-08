#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void out_string(char *buffer, const int buf_size, int *pos, char *string)
{
    int str_pos = 0;

    while (string[str_pos] != '\0' && *pos < buf_size - 1)
    {
        buffer[*pos] = string[str_pos];
        (*pos)++;
        str_pos++;
    }

    return;
}

int count_len_str(const char *string)
{
    int i = 0;

    while (string[i] != '\0')
        i++;

    return i;
}

void int_to_str(int value, char *string)
{
    if (value == 0)
    {
        string[0] = '0';
        string[1] = '\0';
        return;
    }

    int pos = 0;
    int num = 0;

    unsigned int value_buff_1 = value;
    if (value < 0)
    {
        string[pos] = '-';
        value_buff_1 = -value;
        pos++;
    }

    unsigned int value_buff_2 = value_buff_1;

    while (value_buff_1 != 0)
    {
        num++;
        value_buff_1 /= 10;
    }

    for (int i = num - 1; i >= 0; i--)
    {
        string[i + pos] = value_buff_2 % 10 + '0';
        value_buff_2 /= 10;
    }

    string[num + pos] = '\0';

    return;
}

char system_16(int num)
{
    switch (num)
    {
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }
    return '0';
}

void convert_num_sys(unsigned short value, char *string)
{
    int num = 0;
    unsigned short value_buff = value;

    while (value_buff != 0)
    {
        num++;
        value_buff /= 16;
    }

    for (int i = num - 1; i >= 0; i--)
    {
        if (value % 16 < 10)
            string[i] = value % 16 + '0';
        else
            string[i] = system_16(value % 16);
        value /= 16;
    }

    if (num == 0 && value == 0)
    {
        string[num] = '0';
        num++;
    }

    string[num] = '\0';

    return;
}

void check_spec(char *buffer, const int buf_size, int *pos, va_list *args, const char *spec, int *num)
{
    if (spec[0] == 's')
    {
        int i = 1;

        char *string = va_arg(*args, char*);

        (*num) += count_len_str(string);

        out_string(buffer, buf_size, pos, string);

        while (spec[i] != '\0')
        {
            if (*pos < buf_size - 1)
            {
                buffer[*pos] = spec[i];
                (*pos)++;
            }
            i++;
            (*num)++;
        }
    }
    else if (spec[0] == 'i')
    {
        int i = 1;
        char string[12];

        int value = va_arg(*args, int);

        int_to_str(value, string);

        (*num) += count_len_str(string);

        out_string(buffer, buf_size, pos, string);

        while (spec[i] != '\0')
        {
            if (*pos < buf_size - 1)
            {
                buffer[*pos] = spec[i];
                (*pos)++;
            }
            i++;
            (*num)++;
        }
    }
    else if (spec[0] == 'h' && spec[1] == 'X')
    {
        int i = 2;
        char string[12];

        unsigned short value = va_arg(*args, unsigned int);

        convert_num_sys(value, string);

        (*num) += count_len_str(string);

        out_string(buffer, buf_size, pos, string);

        while (spec[i] != '\0')
        {
            if (*pos < buf_size - 1)
            {
                buffer[*pos] = spec[i];
                (*pos)++;
            }
            i++;
            (*num)++;
        }
    }
    else
    {
        int i = 0;
        if (spec[0] == 'h' || spec[0] == 'l' || spec[0] == 'j' || spec[0] == 'z' || spec[0] == 't' || spec[0] == 'L')
            i = 1;
        if (i == 1 && (spec[1] == 'h' || spec[0] == 'l'))
            i = 2;

        while (spec[i] != '\0')
        {
            if (*pos < buf_size - 1)
            {
                buffer[*pos] = spec[i];
                (*pos)++;
            }
            i++;
            (*num)++;
        }
    }
}

int my_snprintf(char *buffer, const int buf_size, const char *format, ...)
{
    if (!format || (!buffer && buf_size != 0))
        return -1;

    int i = 0;
    int pos = 0;
    int num = 0;
    int spec_pos = 0;
    char spec[4];
    va_list args;

    va_start(args, format);

    
    while (format[i] != '\0')
    {
        spec_pos = 0;
        if (format[i] == '%')
        {
            i++;
            while (isalpha(format[i]) != 0 && spec_pos < 3)
            {
                spec[spec_pos] = format[i];
                i++;
                spec_pos++;
            }
            if (spec_pos == 0 && format[i] == '%')
            {
                spec[spec_pos] = '%';
                spec_pos++;
                i++;
            }
            spec[spec_pos] = '\0';
            check_spec(buffer, buf_size, &pos, &args, spec, &num);
        }

        if (format[i] != '%' && pos < buf_size - 1)
        {
            buffer[pos] = format[i];
            pos++;
        }
        if (format[i] != '%' && format[i] != '\0')
        {
            i++;
            num++;
        }
    }
    if (buffer)
        buffer[pos] = '\0';
    va_end(args);
    return num;
}
