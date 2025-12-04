/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:17:11 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 19:22:12 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_parse_info *info;
	
	info = detect_input_error(argc, argv);
	// print_int_ptr(info->nums, info->count);
	init_stacks(&stack_a, &stack_b, info);
	// print_stack(stack_a.head, &stack_a);
	solve(&stack_a, &stack_b);
	// print_stack(stack_a.head, &stack_a);
	stackclear(&stack_a.head);
	// printf("%d\n", stacks.head_a->elem);
	// printf("%d\n", stacks.tail_a->elem);
	// stackclear(&stacks.head_a);
	return (0);
}

void	init_stacks(t_stack *stack_a, t_stack *stack_b, t_parse_info *info)
{
	stack_b->head = NULL;
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
	create_stack(stack_a, info);
	indexer(stack_a, info);
}

void	print_stack(t_node *node, t_stack *stack)
{
	int	i;

	if (!node)
		return ;
	i = 1;
	printf("Stack: ");
	while (node)
	{
		printf("%d", node->elem);
		if (node != stack->tail)
			printf(" <--> ");
		node = node->next;
		i++;
	}
	printf("\nHead: %d; Tail: %d\n", stack->head->elem, stack->tail->elem);
}

void	print_int_ptr(int *nums, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("Número %d: %d\n", i + 1, nums[i]);
		i++;
	}
}
