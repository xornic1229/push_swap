/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:50:30 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 19:19:27 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	sort3(t_stack *stack)
{
	t_node	*head;
	int	n1;
	int	n2;
	int	n3;

	head = stack->head;
	n1 = head->elem;
	n2 = head->next->elem;
	n3 = head->next->next->elem;
	// printf("Número 1: %d\nNúmero 2: %d\nNúmero 3: %d\n", n1, n2, n3);
	if (n1 > n2 && n1 < n3)
		swap(stack, 'a', 1);
	else if (n1 > n3 && n2 < n3)
		rotate(stack, 'a', 1);
	else if (n1 < n2 && n1 > n3)
		reverse_rotate(stack, 'a', 1);
	else if (n1 < n3 && n2 > n3)
	{
		swap(stack, 'a', 1);
		rotate(stack, 'a', 1);
	}
	else if (n1 > n2 && n2 > n3)
	{
		swap(stack, 'a', 1);
		reverse_rotate(stack, 'a', 1);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	min_pos;

	while (stack_a->size > 3)
	{
		min_index = get_min_index(stack_a);
		min_pos = count_until_index(stack_a->head, min_index);
		
		if (min_pos <= stack_a->size / 2)
		{
			while (stack_a->head->index != min_index)
				rotate(stack_a, 'a', 1);
		}
		else
		{
			while (stack_a->head->index != min_index)
				reverse_rotate(stack_a, 'a', 1);
		}
		push(stack_b, stack_a, 'b', 1);
	}
	sort3(stack_a);
	while (stack_b->size > 0)
		push(stack_a, stack_b, 'a', 1);
}

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
		swap(stack_a, 'a', 1);
	else if (stack_a->size == 3)
		sort3(stack_a);
	else if (stack_a->size > 3)
		sort_small(stack_a, stack_b);
	// print_stack(stack_a->head, stack_a);
	// printf("\nSize: %d\n\n", stack_a->size);
	// // // printf("Elemento eliminado: %d\n", stack_pop(stack_a));
	// push(stack_b, stack_a, 'b', 1);
	// push(stack_b, stack_a, 'b', 1);
	// print_stack(stack_a->head, stack_a);
	// printf("\nSize: %d\n\n", stack_a->size);
	// print_stack(stack_b->head, stack_b);
	// printf("\nSize: %d\n\n", stack_b->size);
	// else if (stacksize(stacks->head_a) == 3)
	// 	sort3(stacks);
	// // else if (stacksize(stacks->head_a) >= 5)
	// 	pb(stacks);
	// pb(stacks);

}

