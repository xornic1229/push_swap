/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:03:19 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:23:14 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->elem > current->next->elem)
			return (0);
		current = current->next;
	}
	return (1);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	min_node = current;
	while (current)
	{
		if (current->elem < min_node->elem)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (!stack || !stack->head)
		return (NULL);
	current = stack->head;
	max_node = current;
	while (current)
	{
		if (current->elem > max_node->elem)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

int	get_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_index;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min_index = current->index;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}
