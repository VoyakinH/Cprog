#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H
#include <stdarg.h>
#include <ctype.h>

int my_snprintf(char *buffer, int buf_size, const char *format, ...);
void out_string(char *buffer, const int buf_size, int *pos, char *string);
int count_len_str(const char *string);
void int_to_str(int value, char *string);
char system_16(int num);
void convert_num_sys(unsigned short value, char *string);
void check_spec(char *buffer, const int buf_size, int *pos, va_list *args, const char *spec, int *num);

#endif  //MY_SNPRINTF_H
