#include <stdio.h>
#include "defines.h"
#include <inttypes.h>

int read_two_int(FILE *f, int *x, int *y) {
    if (fscanf(f, "%d %d", x, y) == 2 && *x > 0 && *y > 0) {
        return OK;
    }
    else {
        return READ_SIZE_ERR;
    }
}

int read_two_power(FILE *f, int *x, int *y) {
    if (fscanf(f, "%d %d", x, y) == 2 && *x >= 0 && *y >= 0) {
        return OK;
    }
    else {
        return READ_POWER_ERR;
    }
}

void out_arr(int64_t ***a_p, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%" PRId64, (*a_p)[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return;
}
