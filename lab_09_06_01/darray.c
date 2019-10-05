#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "defines.h"

int read_array(int x, int y, int64_t **a, int64_t ***a_p) {
    int i, j;
    int64_t *new_a = malloc(x * y * sizeof(int64_t));
    int64_t **new_a_p = malloc(x * sizeof(int64_t*));
    int64_t s;
    if (new_a && new_a_p) {
        *a = new_a;
        *a_p = new_a_p;
        new_a = NULL;
        new_a_p = NULL;
    }
    else {
        return READ_ARR_ERR;
    }
    for (i = 0; i < x; i++) {
        (*a_p)[i] = *a + i * y;
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (scanf("%" PRId64, &s) != 1) {
                return READ_ARR_ERR;
            }
            else {
                (*a_p)[i][j] = s;
            }
        }
    }
    return OK;
}

int create_arr(int64_t **res, int64_t ***res_p, int n) {
    int64_t *new_a = malloc(n * n * sizeof(int64_t));
    int64_t **new_a_p = malloc(n * sizeof(int64_t*));
    if (new_a && new_a_p) {
        *res = new_a;
        *res_p = new_a_p;
        new_a = NULL;
        new_a_p = NULL;
    }
    else {
        return CREATE_ARR_ERR;
    }
    for (int i = 0; i < n; i++) {
        (*res_p)[i] = *res + i * n;
    }
    return OK;
}

int new_size(int64_t **a, int64_t ***a_p, int x, int y) {
    int64_t *new_a = realloc(*a, sizeof(int64_t) * x * y);
    int64_t **new_a_p = realloc(*a_p, x * sizeof(int64_t*));
    if (new_a && new_a_p) {
        *a = new_a;
        *a_p = new_a_p;
        for (int i = 0; i < x; i++) {
            (*a_p)[i] = *a + i * y;
        }
        new_a = NULL;
        new_a_p = NULL;
    }
    else {
        return MEM_ERR;
    }
    return OK;
}
