
typedef struct mat
{
	int **arr;
} mat;

int init_arr(mat **array, int n, int m);
int read_arr(mat *array, int n, int m);
void out_arr(mat *array, int n, int m);
void free_arr(mat *array, int n);
int count_diag(int n, int m);
int init_triangle_arr(mat **array, int n, int m);
int rotate_arr(mat *array, mat *t_array, int n, int m, int t_n, int t_m);