#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int main()
{
    int rc = OK, n, p;
    double u1 = 0, u2 = 0;
    if (read_n(stdin, &n) != OK)
        rc = READ_N_ERR;
    if (rc == OK)
    {
        double *a = read_array(n, &rc);
        if (rc == OK)
        {
            if (read_p(stdin, &p, n) != OK)
                rc = READ_P_ERR;
            if (rc == OK)
            {
                count_u1(a, n, &u1);
                del(a, &n, u1);
                new_size(&a, n);
                count_u2(a, n, &u2);
                insert(a, &n, p, u2);
                out_arr(a, n);
            }
        }
        if (a)
            free(a);
    }
    return rc;
}
