#include "push_swap.h"

void parse_args(t_stack *a, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        int value = atoi(argv[i]); // Convert argument to integer

        // Allocate memory for the integer and store the value
        int *content = malloc(sizeof(int));
        if (!content)
        {
            write(2, "Error\n", 6); // Handle memory allocation error
            return;
        }
        *content = value; // Assign value to the allocated memory

        // Create a new node with the pointer to the integer
        t_list *new_node = ft_lstnew(content);
        if (!new_node)
        {
            free(content); // Free the allocated memory in case of error
            write(2, "Error\n", 6);
            return;
        }

        // Add the new node to the stack
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