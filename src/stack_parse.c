/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:17:23 by jaialons          #+#    #+#             */
/*   Updated: 2026/01/16 19:48:17 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_and_push(t_stack *stack, const char *str)
{
	long	nb;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	if (has_duplicate(stack, (int)nb))
		return (0);
	node = create_node((int)nb);
	if (!node)
		return (0);
	put_node_at_bottom(stack, node);
	return (1);
}

int	init_stack_a_one_arg(t_stack *stack, const char *arg)
{
	char	**nums;
	int		i;

	if (!arg || !*arg)
		return (0);
	nums = ft_split(arg, ' ');
	if (!nums)
		return (0);
	i = 0;
	while (nums[i])
	{
		if (!parse_and_push(stack, nums[i]))
			return (free_split(nums), 0);
		i++;
	}
	free_split(nums);
	return (1);
}

int	init_stack_a_multiple_args(t_stack *stack, const char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!parse_and_push(stack, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
