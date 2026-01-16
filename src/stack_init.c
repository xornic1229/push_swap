/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:46:10 by jaialons          #+#    #+#             */
/*   Updated: 2026/01/16 19:17:02 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int elem)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->elem = elem;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	put_node_at_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	stack->size++;
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->elem == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
