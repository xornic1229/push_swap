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
#include <stdio.h>

void	probar_stack(t_stack *stack_a,t_stack *stack_b)
{
    t_node	*current_a;
    t_node	*current_b;
    for (int i = 0; i < 3; i++)
        push(stack_a, stack_b, 'b');
    rotate(stack_a, 'a');
    swap(stack_a, 'a');
    reverse_rotate(stack_a, 'a');
    printf("A - B\n");
    current_a = stack_a->head;
    current_b = stack_b->head;

    while (current_a != NULL || current_b != NULL)
    {
        if (current_a == NULL)
            printf("  - %d\n", current_b->elem);
        else if (current_b == NULL)
            printf("%d -  \n", current_a->elem);
        else
            printf("%d - %d\n", current_a->elem, current_b->elem);
        current_a = current_a->next;
        current_b = current_b->next;
    }
}

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
