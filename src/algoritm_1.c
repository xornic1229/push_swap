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

#include "../include/push_swap.h"

void	push_swap_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	if (!stack_a || is_sorted(stack_a))
		return ;
	size_a = stack_a->size;
	index_stack(stack_a);
	if (size_a == 2)
		swap(stack_a, 'a');
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_larger(stack_a, stack_b);
}

void	sort_three(t_stack *stack)
{
	int a;
	int b;
	int c;

	a = stack->head->index;
	b = stack->head->next->index;
	c = stack->head->next->next->index;
	if (a > b && b < c && a < c)
        swap(stack, 'a');
    else if (a > b && b > c)
    {
        swap(stack, 'a');
        reverse_rotate(stack, 'a');
    }
    else if (a > b && b < c && a > c)
        rotate(stack, 'a');
    else if (a < b && b > c && a < c)
    {
        swap(stack, 'a');
        rotate(stack, 'a'); 
    }
    else if (a < b && b > c && a > c)
        reverse_rotate(stack, 'a'); 
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size >3)
	{
		if (stack_a->head->index == 0 || stack_a->head->index == 1)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
	}
	sort_three(stack_a);
	while (stack_b->size>0)
	{
		if (stack_b->head->index == 0)
		{
			rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
		}
		else
			push(stack_b, stack_a, 'a');
	}
}

void sort_larger(t_stack *stack_a, t_stack *stack_b)
{
    int max_bits = get_max_bits(stack_a->size);
    int i, count;

    for (i = 0; i < max_bits; i++)
    {
        count = stack_a->size;
        while (count > 0)
        {
            int index = stack_a->head->index;
            if (((index >> i) & 1) == 1)
                push(stack_a, stack_b, 'b');
            else
                rotate(stack_a, 'a');
            count--;
        }

        while (stack_b->size > 0)
            push(stack_b, stack_a, 'a');
    }
}

