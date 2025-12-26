/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:11:41 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:19:35 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	if (!stack_a || is_sorted(stack_a))
		return ;
	size_a = stack_a->size;
	if (size_a == 2)
		swap(stack_a);
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a <= 7)
		sort_seven(stack_a, stack_b, size_a);
	else
		sort_larger(stack_a, stack_b);
}

void	sort_three(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->head;
	second = first->next;
	third = second->next;
	if (first->elem > second->elem && second->elem > third->elem)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (first->elem > second->elem && first->elem > third->elem)
		rotate(stack);
	else if (second->elem > first->elem && second->elem > third->elem)
	{
		reverse_rotate(stack);
		swap(stack);
	}
}

void	sort_seven(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	min_index;
	int	i;
	int	distance_from_head;
	int	distance_from_tail;

	i = 0;
	while (i < n - 3)
	{
		min_index = get_min_index(stack_a);
		distance_from_head = count_until_index(stack_a->head, min_index) - 1;
		distance_from_tail = stack_a->size - distance_from_head - 1;
		if (distance_from_head <= distance_from_tail)
		{
			while (stack_a->head->index != min_index)
				rotate(stack_a);
		}
		else
		{
			while (stack_a->head->index != min_index)
				reverse_rotate(stack_a);
		}
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a);
		i++;
	}
	sort_three(stack_a);
	i = 0;
	while (i < n - 3)
	{
		push(stack_a, stack_b);
		i++;
	}
}

void	sort_larger(t_stack *stack_a, t_stack *stack_b)
{
	// TODO: Implementar algoritmo para stacks más grandes
	// Opciones:
	// - Algoritmo Radix (eficiente)
	// - Algoritmo Turk
	// - Algoritmo Quicksort adaptado
	// - Bubble sort con optimizaciones
	(void)stack_a;
	(void)stack_b;
}
