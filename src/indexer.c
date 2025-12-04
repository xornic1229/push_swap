/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:50:14 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/02 18:10:05 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	indexer(t_stack *stack, t_parse_info *info)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		node->index = get_index(node->elem, info);
		node = node->next;
	}
	free(info->nums);
	free(info);
}

int	get_index(int elem, t_parse_info *info)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (i < info->count)
	{
		if (info->nums[i] < elem)
			index++;
		i++;
	}
	return (index);
}
