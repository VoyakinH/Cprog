#ifndef FUNC_H
#define FUNC_H

typedef struct list
{
    int factor;
    int pow;
    struct list *next_factor;
} list;

int read_mode(FILE *f, char mode[]);
int check_mode(FILE *fin, const char mode[], list **factors);
int read_int(FILE *f, int *val);
int init_list(list **factors);
int increase_list(list **factors);
void free_list(list **factors);
void output_list(FILE *f, list *factors);
int int_to_list(FILE *fin, list **factors);
int factorize(list **factors, int val);
void double_every_pow(list *factors);
int out_func(FILE *fin, list **factors);
int sqr_func(FILE *fin, list **factors);
int mul_func(FILE *fin, list **factors);
void combine_lists(list **factors_both, list **factors);

#endif
