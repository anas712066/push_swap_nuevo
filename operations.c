#include "push_swap.h"

// Función para inicializar una nueva pila
t_stack *init_stack(void)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

// Función para liberar la memoria de una pila
void free_stack(t_stack *stack)
{
    t_list *current = stack->top;
    t_list *next;
    
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// Función para realizar la operación de swap en una pila
void swap(t_stack *stack)
{
    t_list *first;
    t_list *second;
    
    if (stack->size < 2)
        return;
    
    first = stack->top;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

// Función para realizar la operación de push de src a dest
void push(t_stack *src, t_stack *dest)
{
    t_list *temp;
    
    if (src->size == 0)
        return;
    
    temp = src->top;
    src->top = src->top->next;
    temp->next = dest->top;
    dest->top = temp;
    
    src->size--;
    dest->size++;
}

// Función para realizar la operación de rotate en una pila
void rotate(t_stack *stack)
{
    t_list *temp;
    t_list *current;
    
    if (stack->size < 2)
        return;
    
    temp = stack->top;
    stack->top = stack->top->next;
    
    current = stack->top;
    while (current->next)
        current = current->next;
    
    temp->next = NULL;
    current->next = temp;
}

// Función para realizar la operación de reverse rotate en una pila
void reverse_rotate(t_stack *stack)
{
    t_list *last;
    t_list *second_last;
    
    if (stack->size < 2)
        return;
    
    last = stack->top;
    second_last = NULL;
    
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    
    second_last->next = NULL;
    last->next = stack->top;
    stack->top = last;
}