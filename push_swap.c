#include "push_swap.h"

void push_swap(t_stack *a)
{
    t_stack *b = init_stack();
    
    if (check_errors(argv))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return;
    }
    
    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        return;
    }
    
    if (a->size == 2)
        sort_two(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size <= 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
    
    free_stack(a);
    free_stack(b);
}