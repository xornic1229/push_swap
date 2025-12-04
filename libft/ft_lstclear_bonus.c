/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:13:15 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/09/25 18:25:25 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual_node;
	t_list	*next_node;

	if (!lst || !del || !*lst)
		return ;
	actual_node = *lst;
	while (actual_node)
	{
		next_node = actual_node->next;
		ft_lstdelone(actual_node, del);
		actual_node = next_node;
	}
	*lst = NULL;
}
