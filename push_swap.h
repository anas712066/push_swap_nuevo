#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"  // Usamos tu libft con listas y file descriptors

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

// Funciones principales
void	push_swap(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);

// Algoritmos para pocos números
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

// Operaciones de stack
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// Utilidades
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		find_max_bits(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);

// Parsing y validaciones
void	parse_args(t_stack *a, char **argv);
int		check_errors(char **argv);

#endif