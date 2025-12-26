/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:16:20 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/19 18:45:03 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
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

t_stack				*init_stack(void);
void				init_stack_a_one_arg(t_stack *stack_a, char const *argv);
void				init_stack_a_multiple_args(t_stack *stack_a,
						char const *argv[]);
t_node				*create_node(int elem);
void				put_node_at_bottom(t_stack *stack, t_node *new_node);
void				swap(t_stack *stack);
void				push(t_stack *from, t_stack *to);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

