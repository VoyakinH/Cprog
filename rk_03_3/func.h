#ifndef FUNC_H
#define FUNC_H

typedef struct mat
{
	int **arr;
    int n;
    int m;
} mat;

int read_size(FILE *f, mat *array);
int init_arr(mat **array);
int read_arr(FILE *f, mat *array);
void rotate_arr(mat *array, mat *new_array);
void out_arr(FILE *f, mat *new_array);
void free_arr(mat *array);

#endif

