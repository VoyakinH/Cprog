#include <stdio.h>

int read_n(FILE *f, int *n);
int read_array(int n, double **a);
void count_u1(double *a, int n, double *s);
void del(double *a, int *n, double u1);
int read_p(FILE *f, int *p, int n);
void count_u2(double *a, int n, double *u2);
void out_arr(double *a, int n);
void insert(double *a, int *n, int p, double u2);
int new_size(double **a, int n);
int comp(double u1, double *p1, double *p2);
//void slip(int *n, int j, double *p);
