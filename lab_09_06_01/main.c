#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "func.h"
#include "defines.h"

int main()
{
    int n, m, p, q, ro, nu, rc = OK;
    int64_t *a = 0, **a_p = 0, *b = 0, **b_p = 0;
    rc = read_two_int(stdin, &n, &m);
    rc += read_array(n, m, &a, &a_p);
    if (rc == OK)
    {
        rc = read_two_int(stdin, &p, &q);
        rc += read_array(p, q, &b, &b_p);
        if (rc == OK)
        {
            make_square(&a_p, &n, &m);
            make_square(&b_p, &p, &q);
            rc = new_size(&a, &a_p, n, m);
            rc += new_size(&b, &b_p, p, q);
            if (rc == OK)
            {
                if (n < p)
                {
                    rc = increase_row_number(&a, &a_p, &n, m, p);
                    rc += increase_col_number(&a, &a_p, n, &m, q);
                }
                else
                {
                    rc = increase_row_number(&b, &b_p, &p, q, n);
                    rc += increase_col_number(&b, &b_p, p, &q, m);
                }
                if (rc == OK)
                {
                    rc = read_two_power(stdin, &ro, &nu);
                    if (rc == OK)
                    {
                        int64_t *res = 0, **res_p = 0;
                        rc = create_arr(&res, &res_p, n);
                        if (rc == OK)
                        {
                            fill(&res_p, &a_p, n, ro);
                            count(&a_p, &b_p, &res_p, n, ro, nu);
                            out_arr(&res_p, n, n);
                        }
                        free(res);
                        free(res_p);
                    }
                }
            }
        }
        free(b);
        free(b_p);
    }
    free(a);
    free(a_p);
    return rc;
}
