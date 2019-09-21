#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "defines.h"

int main()
{
    int rc = OK, n, p;
    double u1 = 0, u2 = 0;
    rc = read_n(stdin, &n);
    if (rc == OK)
    {
        double *a;
        rc = read_array(n, &a);
        if (rc == OK)
        {
            rc = read_p(stdin, &p, n);
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
