#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_list	*temp;
	t_list	*next;

	if (!stack)
		return ;
	temp = stack->top;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(stack);
}

// Encontrar el índice del máximo valor
int find_max_index(t_stack *stack)
{
    int max_index = 0;
    int max_value = stack->top->content;
    t_list *current = stack->top;
    int i = 0;
    
    while (current)
    {
        if (current->content > max_value)
        {
            max_value = current->content;
            max_index = i;
        }
        current = current->next;
        i++;
    }
    return (max_index);
}

// Encontrar el índice del mínimo valor
int find_min_index(t_stack *stack)
{
    int min_index = 0;
    int min_value = stack->top->content;
    t_list *current = stack->top;
    int i = 0;
    
    while (current)
    {
        if (current->content < min_value)
        {
            min_value = current->content;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return (min_index);
}

// Encontrar el número máximo de bits en la pila
int find_max_bits(t_stack *stack)
{
    int max_value = stack->top->content;
    t_list *current = stack->top;
    
    while (current)
    {
        if (current->content > max_value)
            max_value = current->content;
        current = current->next;
    }
    
    int bits = 0;
    while ((max_value >> bits) != 0)
        bits++;
    return (bits);
}