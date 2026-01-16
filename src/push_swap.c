/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:23:25 by jaialons          #+#    #+#             */
/*   Updated: 2026/01/16 20:17:10 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b || argc == 1)
		return (1);
	if (argc == 2)
	{
		if (!init_stack_a_one_arg(stack_a, argv[1]))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	else
	{
		if (!init_stack_a_multiple_args(stack_a, argv))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	if (stack_a->size == 0)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	push_swap_algorithm(stack_a, stack_b);
	return (0);
}
