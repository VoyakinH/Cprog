#ifndef func_h
#define FUNC_H
#include <stdio.h>

int read_two_int(FILE *f, int *x, int *y);
int read_array(FILE *f, int x, int y, int64_t **a, int64_t ***a_p);
void out_arr(FILE *f, int64_t **a_p, int x, int y);
int make_square(int64_t **a, int64_t ***a_p, int *n, int *m);
int new_size(int64_t **a, int64_t ***a_p, int x, int y);
int increase_row_number(int64_t **a, int64_t ***a_p, int *n, int m, int p);
int increase_col_number(int64_t **a, int64_t ***a_p, int n, int *m, int q);
int read_two_power(FILE *f, int *x, int *y);
void fill(int64_t ***res_p, int64_t ***a_p, int n, int ro);
int create_arr(int64_t **res, int64_t ***res_p, int n);
void count_result(int64_t ***a_p, int64_t ***b_p, int64_t ***res_p, int n, int ro, int nu);

#endif
