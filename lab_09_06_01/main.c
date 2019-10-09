#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "func.h"
#include "defines.h"

int main()
{
    int n = 0, m = 0, p = 0, q = 0, ro = 0, nu = 0, rc = OK;
    int64_t *a = NULL, **a_p = NULL, *b = NULL, **b_p = NULL;
    rc = read_two_int(stdin, &n, &m);
    if (rc == OK)
    {
        rc = read_array(stdin, n, m, &a, &a_p);
        if (rc == OK)
        {
            rc = read_two_int(stdin, &p, &q);
            if (rc == OK)
            {
                rc = read_array(stdin, p, q, &b, &b_p);
                if (rc == OK)
                {
                    rc = make_square(&a, &a_p, &n, &m);
                    rc += make_square(&b, &b_p, &p, &q);
                    if (rc == OK)
                    {
                        if (n < p)
                        {
                            rc = increase_row_number(&a, &a_p, &n, m, p);
                            rc += increase_col_number(&a, &a_p, n, &m, q);
                        }
                        else if (n != p)
                        {
                            rc = increase_row_number(&b, &b_p, &p, q, n);
                            rc += increase_col_number(&b, &b_p, p, &q, m);
                        }
                        if (rc == OK)
                        {
                            rc = read_two_power(stdin, &ro, &nu);
                            if (rc == OK)
                            {
                                int64_t *res = NULL, **res_p = NULL;
                                rc = create_arr(&res, &res_p, n);
                                if (rc == OK)
                                {
                                    fill(&res_p, &a_p, n, ro);
                                    count_result(&a_p, &b_p, &res_p, n, ro, nu);
                                    out_arr(stdout, res_p, n, n);
                                }
                                if (res)
                                    free(res);
                                if (res_p)
                                    free(res_p);
                            }
                        }
                    }
                }
                if (b)
                    free(b);
                if (b_p)
                    free(b_p);
            }
        }
        if (a)
            free(a);
        if (a_p)
            free(a_p);
    }
    return rc;
}
