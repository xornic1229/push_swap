/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:35:17 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 18:51:30 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

t_node	*new_node(int elem, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->elem = elem;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// int	stacksize(t_node *stack)
// {
// 	int		count;
// 	t_node	*aux;

// 	count = 0;
// 	aux = stack;
// 	while (aux)
// 	{
// 		count++;
// 		aux = aux->next;
// 	}
// 	return (count);
// }

void	stackclear(t_node **stack)
{
	t_node	*actual_node;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;
	actual_node = *stack;
	while (actual_node)
	{
		next_node = actual_node->next;
		free(actual_node);
		actual_node = next_node;
	}
	*stack = NULL;
}


// void	stackadd_back(t_stack **stack, t_stack *new)
// {
// 	t_stack	*last;

// 	if (!stack || !new)
// 		return ;
// 	if (!*stack)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	last = *stack;
//     while (last->next)
//         last = last->next;
//     last->next = new;
// }

// t_node	*stacklast(t_node *stack)
// {
// 	t_node	*last;

// 	if (!stack)
// 		return (NULL);
// 	last = stack;
// 	while (last->next)
// 		last = last->next;
// 	return (last);
// }


void	stack_push(t_stack *stack, int index, int elem)
{
	t_node	*temp;

	temp = new_node(elem, index);
	if (!temp)
		error_and_exit();
	temp->next = stack->head;
	if (temp->next)
		stack->head->prev = temp;
	else
		stack->tail = temp;
	stack->head = temp;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int	elem;

	if (!stack || !stack->head)
		return (0);  // Return 0 instead of exit, this should not happen anyway
	node = stack->head;
	elem = node->elem;
	stack->head = node->next;
	if (node->next)
		node->next->prev = NULL;
	else
		stack->tail = NULL;
	free(node);
	node = NULL;
	stack->size--;
	return (elem);
}

void	create_stack(t_stack *stack, t_parse_info *info)
{
	int		i;
	t_node	*prev;
	t_node	*next;

	stack->head = new_node(info->nums[0], 0);
	prev = stack->head;
	i = 1;
	while (i < info->count)
	{
		next = new_node(info->nums[i], 0);
		if (!next)
		{	
			stackclear(&stack->head);
			free(info->nums);
			free(info);
			error_and_exit();
		}
		prev->next = next;
		next->prev = prev;
		prev = next;
		i++;
	}
	stack->tail = prev;
	stack->size = info->count;
}
