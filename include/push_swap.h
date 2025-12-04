/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:15:35 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/03 18:22:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_stack
// {
// 	int				elem;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }					t_stack;

// typedef struct s_stacks
// {
// 	t_stack			*head_a;
// 	t_stack			*head_b;
// 	t_stack			*tail_a;
// 	t_stack			*tail_b;
// }					t_stacks;

typedef struct s_node
{
	int				elem;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

typedef struct s_parse_info
{
	int				*nums;
	int				count;
}					t_parse_info;

void				error_and_exit(void);
t_parse_info		*detect_input_error(int argc, char **argv);
int					*parse_int(int argc, char **argv, t_parse_info *info);
void				check_for_doubles(t_parse_info *info);
void				check_int_size(char **nums_matrix, int *nums,
						t_parse_info *info);
int					check_integers(int argc, char **argv);
void				init_stacks(t_stack *stack_a, t_stack *stack_b,
						t_parse_info *info);
void				create_stack(t_stack *stack, t_parse_info *info);
void				indexer(t_stack *stack, t_parse_info *info);
int					get_index(int elem, t_parse_info *info);
void				print_stack(t_node *node, t_stack *stack);
void				print_int_ptr(int *nums, int count);
void				stackclear(t_node **stack);
void				stack_push(t_stack *stack, int index, int elem);
int					stack_pop(t_stack *stack);
void				swap(t_stack *stack, char c, int cond);
void				rotate(t_stack *stack, char c, int cond);
void				reverse_rotate(t_stack *stack, char c, int cond);
void				push(t_stack *stack1, t_stack *stack2, char c, int cond);
void				solve(t_stack *stack_a, t_stack *stack_b);
void				sort_small(t_stack *stack_a, t_stack *stack_b);
int					check_sorted(t_stack *stack);
void				sort3(t_stack *stack);
int					get_min_index(t_stack *stack);
int					count_until_index(t_node *node, int searching_index);

// void				solve(t_stacks *stacks);
// int					stacksize(t_stack *stack);
// void				sort2(t_stacks *stacks);
// void				sa(t_stack *stack_a);
// void				print_stack(t_stack *head);
// t_stack				*stacklast(t_stack *stack);
// void				sort3(t_stacks *stacks);
// void				sort_combinations(t_stacks *stacks, int n1, int n2, int n3);
// void				rra(t_stacks *stacks);
// void				rrb(t_stacks *stacks);
// void				ra(t_stacks *stacks);
// void				rb(t_stacks *stacks);
// void				b_is_empty(t_stacks *stacks, t_stack *temp);

#endif