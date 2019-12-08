#ifndef FUNC_H
#define FUNC_H

typedef struct stack
{
    int factor;
    int pow;
    struct stack *next_factor;
} stack;

int read_mode(FILE *f, char mode[]);
int check_mode(const char mode[]);
int read_int(FILE *f, int *val);
int init_list(stack **factors);
int increase_stack(stack **factors);
void free_stack(stack **factors);
void output_stack(FILE *f, stack *factors);

#endif
