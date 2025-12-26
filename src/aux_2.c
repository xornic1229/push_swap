/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:20:13 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:20:28 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_until_index(t_node *head, int index)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		if (head->index == index)
			return (count);
		head = head->next;
	}
	return (-1);
}
