/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:20:59 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/19 18:39:47 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->tail = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from->head)
		return ;
	node = from->head;
	from->head = node->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	node->next = to->head;
	node->prev = NULL;
	if (to->head)
		to->head->prev = node;
	else
		to->tail = node;
	to->head = node;
	from->size--;
	to->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*new_head;

	if (stack->size < 2)
		return ;
	first = stack->head;
	new_head = first->next;
	stack->head = new_head;
	new_head->prev = NULL;
	stack->tail->next = first;
	first->prev = stack->tail;
	first->next = NULL;
	stack->tail = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*new_tail;

	if (stack->size < 2)
		return ;
	last = stack->tail;
	new_tail = last->prev;
	stack->tail = new_tail;
	new_tail->next = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	last->prev = NULL;
	stack->head = last;
}
