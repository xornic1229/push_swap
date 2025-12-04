/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:07:40 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 18:21:07 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	check_sorted(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return (1);
	temp = stack->head;
	while (temp && temp->next)
	{
		if (temp->elem > temp->next->elem)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_min_index(t_stack *stack)
{
	t_node	*temp;
	int		min_index;

	temp = stack->head;
	min_index = temp->index;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->index < min_index)
			min_index = temp->index;
	}
	return (min_index);
}

int	count_until_index(t_node *node, int searching_index)
{
	int	count;

	count = 0;
	while (node && node->index != searching_index)
	{
		node = node->next;
		count++;
	}
	return (count);
}
