#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
    {
        write(2, "Error\n", 6);
        return (1);
    }

    a = init_stack();
    b = init_stack();

    parse_args(a, argv);

    if (check_errors(argv))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return (1);
    }

    if (!is_sorted(a))
    {
        push_swap(a);
    }

    free_stack(a);
    free_stack(b);
    return (0);
}