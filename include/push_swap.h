/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:16:20 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:16:05 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				elem;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

//init.c
t_stack				*init_stack(void);
void				init_stack_a_one_arg(t_stack *stack_a, char const *argv);
void				init_stack_a_multiple_args(t_stack *stack_a,
						char const *argv[]);
t_node				*create_node(int elem);
void				put_node_at_bottom(t_stack *stack, t_node *new_node);
//operations.c
void				swap(t_stack *stack, int stack_id);
void				push(t_stack *from, t_stack *to, int to_stack_id);
void				rotate(t_stack *stack, int stack_id);
void				reverse_rotate(t_stack *stack, int stack_id);
//aux_1.c
int					is_sorted(t_stack *stack);
int get_max_bits(int size);

//algoritm_1.c
void				push_swap_algorithm(t_stack *stack_a, t_stack *stack_b);
void				sort_three(t_stack *stack);
void				sort_small(t_stack *stack_a, t_stack *stack_b);
void				sort_larger(t_stack *stack_a, t_stack *stack_b);
//index.c
void				index_stack(t_stack *stack);
int					*bubble_sort(int *arr, int n);
int					index_search(int *arr, int n, int elem);
