#include "push_swap.h"

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits = find_max_bits(a);
    int i = 0;
    int j;
    int size = a->size;
    
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            int num = a->top->content;
            if ((num >> i) & 1)
                rotate(a);
            else
                push(a, b);
            j++;
        }
        while (b->size > 0)
            push(b, a);
        i++;
    }
}

// Función para verificar si una pila está ordenada
int is_sorted(t_stack *stack)
{
    t_list *current = stack->top;
    
    while (current && current->next)
    {
        if (current->content > current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}

// Función para ordenar dos elementos
void sort_two(t_stack *a)
{
    if (a->top->content > a->top->next->content)
        swap(a);
}

// Función para ordenar tres elementos
void sort_three(t_stack *a)
{
    int first = a->top->content;
    int second = a->top->next->content;
    int third = a->top->next->next->content;
    
    if (first > second && second < third && first < third)
        swap(a);
    else if (first > second && second > third && first > third)
    {
        swap(a);
        reverse_rotate(a);
    }
    else if (first > second && second < third && first > third)
        rotate(a);
    else if (first < second && second > third && first < third)
    {
        swap(a);
        rotate(a);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a);
}

// Función para ordenar cinco elementos
void sort_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        if (a->top->content == find_min_index(a) || a->top->content == find_max_index(a))
            push(a, b);
        else
            rotate(a);
    }
    sort_three(a);
    while (b->size > 0)
        push(b, a);
    if (!is_sorted(a))
        swap(a);
}