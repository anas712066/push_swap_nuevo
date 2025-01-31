#include "push_swap.h"

// Función para parsear argumentos y llenar la pila
void parse_args(t_stack *a, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int value;

        value = atoi(argv[i]);
        t_list *new_node = ft_lstnew(value);
        ft_lstadd_back(&a->top, new_node);
        a->size++;
        i++;
    }
}

// Función para verificar errores en los argumentos
int check_errors(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}