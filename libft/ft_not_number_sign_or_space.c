/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_number_sign_or_space.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:03:34 by jsagaro-          #+#    #+#             */
/*   Updated: 2024/11/28 14:07:09 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_not_number_sign_or_space(int c)
{
	return (!ft_isdigit(c) && !ft_issign(c) && !ft_isspace(c));
}