/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:23:25 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:19:19 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	if (argc == 1)
		return (1);
	else if (argc == 2)
		init_stack_a_one_arg(stack_a, argv[1]);
	else
		init_stack_a_multiple_args(stack_a, argv);
	push_swap_algorithm(stack_a, stack_b);
	return (0);
}
