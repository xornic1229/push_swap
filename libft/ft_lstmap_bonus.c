/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:31:14 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/10/03 15:49:39 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_node(t_list *node, t_list **lst, void (*del)(void *))
{
	if (!node)
	{
		ft_lstclear(lst, del);
		return (0);
	}
	return (1);
}

static int	check_content(t_list *node, t_list **lst, void (*del)(void *))
{
	if (!node->content)
	{
		free(node);
		ft_lstclear(lst, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!check_node(new_node, &new_lst, del))
			return (NULL);
		if (!check_content(new_node, &new_lst, del))
			return (NULL);
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
