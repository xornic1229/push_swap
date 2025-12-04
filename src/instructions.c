/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:33:23 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	swap(t_stack *stack, char c, int cond)
{
	t_node	*temp;
	
	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head->next;
	stack->head->next = temp;
	stack->head->prev = NULL;
	temp->prev = stack->head;
	if (temp->next)
		temp->next->prev = temp;
	else
		stack->tail = temp;
	if (cond)
	{
		write(1, "s", 1);
		write(1, &c, 1);	
		write(1, "\n", 1);	
	}
}

void	rotate(t_stack *stack, char c, int cond)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	stack->head->prev = NULL;
	stack->tail->next = temp;
	temp->prev = stack->tail;
	temp->next = NULL;
	stack->tail = temp;
	if (cond)
	{
		write(1, "r", 1);
		write(1, &c, 1);	
		write(1, "\n", 1);	
	}
}

void	reverse_rotate(t_stack *stack, char c, int cond)
{
	t_node	*temp;

	if (!stack->head || !stack->head->next)
		return ;
	temp = stack->tail;
    stack->tail = temp->prev;
    stack->tail->next = NULL;
    temp->prev = NULL;
    temp->next = stack->head;
    stack->head->prev = temp;
    stack->head = temp;
	if (cond)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *stack1, t_stack *stack2, char c, int cond)
{
	int elem;
	int index;
	
	if (!stack2->head)
		return ;
	index = stack2->head->index;  // Get index BEFORE popping
	elem = stack_pop(stack2);
	stack_push(stack1, index, elem);
	if (cond)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
