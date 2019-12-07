#ifndef FUNC_H
#define FUNC_H
#include "defines.h"

typedef struct exp
{
    int date[DATE_LEN];
    char *technician;
    float *data;
    int num_of_data;
} exp;

int read_set_of_exp(exp **experiments, int *i, FILE *f);
void write_to_file(FILE *f, exp *experiments, int number_of_exp);
float average_data(const exp *experiments, int number_of_exp);
void make_del(exp *experiments, int *number_of_exp);
int read_key(char *key, FILE *f);
int sort_arr(exp *experiments, int number_of_exp, const char *key);
int is_date_valid(const char *got_date, int date[]);
int read_technician(char **surname, FILE *f);
int read_data(float **data, int *num_of_data, FILE *f);
void free_arr(exp **experiments, int number_of_exp);

int comp_string(const void *x1, const void *x2);
int comp_float(const void *x1, const void *x2);
int comp_date(const void *x1, const void *x2);

#endif
