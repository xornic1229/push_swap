/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:46:10 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:19:19 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	init_stack_a_one_arg(t_stack *stack_a, char const *argv)
{
	int		i;
	int		elem;
	t_node	*new_node;

	i = 0;
	while (argv[i])
	{
		elem = 0;
		while (argv[i] == ' ')
			i++;
		while (argv[i] >= '0' && argv[i] <= '9')
		{
			elem = elem * 10 + (argv[i] - '0');
			i++;
		}
		new_node = create_node(elem);
		put_node_at_bottom(stack_a, new_node);
	}
}

void	init_stack_a_multiple_args(t_stack *stack_a, char const *argv[])
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = create_node(ft_atoi(argv[i]));
		put_node_at_bottom(stack_a, new_node);
		i++;
	}
}

t_node	*create_node(int elem)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->elem = elem;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	put_node_at_bottom(t_stack *stack, t_node *new_node)
{
	if (stack->size == 0)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = stack->tail;
		new_node->next = NULL;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}
