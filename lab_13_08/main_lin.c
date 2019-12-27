#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#define OK 0
#define READ_N_ERR -1
#define READ_P_ERR -2
#define READ_ARR_ERR -3
#define MEM_ERR -4

int main()
{
    void *handle = dlopen("libdynarr.so", RTLD_LAZY);
    if (!handle)
    {
        printf("Cannot open library (%s).\n", dlerror());
        return -1;
    }
    //printf("Library is loaded at address %p.\n", (void*) hlib);
    int rc = OK, n, p;
    double u1 = 0, u2 = 0;
    int (*read_n)(FILE *f, int *n) = dlsym(handle,"read_n");
    rc = (*read_n)(stdin, &n);
    if (rc == OK)
    {
        double *a;
        int (*read_array)(int n, double **a) = dlsym(handle,"read_array");
        rc = (*read_array)(n, &a);
        if (rc == OK)
        {
            int (*read_p)(FILE *f, int *p, int n) = dlsym(handle,"read_p");
            rc = (*read_p)(stdin, &p, n);
            if (rc == OK)
            {
                void (*count_u1)(double *a, int n, double *s) = dlsym(handle,"count_u1");
                (*count_u1)(a, n, &u1);
                void (*del)(double *a, int *n, double u1) = dlsym(handle,"del");
                (*del)(a, &n, u1);
                int (*new_size)(double **a, int n) = dlsym(handle,"new_size");
                (*new_size)(&a, n);
                void (*count_u2)(double *a, int n, double *u2) = dlsym(handle,"count_u2");
                (*count_u2)(a, n, &u2);
                void (*insert)(double *a, int *n, int p, double u2) = dlsym(handle,"insert");
                (*insert)(a, &n, p, u2);
                void (*out_arr)(double *a, int n) = dlsym(handle,"out_arr");
                (*out_arr)(a, n);
            }
        }
        if (a)
            free(a);
    }
    dlclose(handle);
    return rc;
}
