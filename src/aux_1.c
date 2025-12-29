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

#include "../include/push_swap.h"

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

int get_max_bits(int size)
{
    int max_num;
	max_num = size - 1;
    int bits = 0;
    while (max_num >> bits)
        bits++;
    return bits;
}
