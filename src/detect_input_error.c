/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_input_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:20:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/02/02 19:03:59 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	check_integers(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (-1);
			// Check for invalid consecutive signs
			if (j > 0 && (argv[i][j] == '+' || argv[i][j] == '-')
				&& (argv[i][j - 1] == '+' || argv[i][j - 1] == '-'))
				return (-1);
			// Check for signs not followed by digits
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& (!argv[i][j + 1] || argv[i][j + 1] == ' '))
				return (-1);
			// Check for digits followed by signs (invalid)
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == '+' || argv[i][j + 1] == '-'))
				return (-1);
			// Count numbers
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_int_size(char **nums_matrix, int *nums, t_parse_info *info)
{
	long	num;
	int		i;

	i = 0;
	while (nums_matrix[i])
	{
		num = ft_atol(nums_matrix[i]);
		if (num > INT_MAX || num < INT_MIN || ft_strlen(nums_matrix[i]) > 11)
		{
			ft_free_matrix(nums_matrix);
			free(nums);
			free(info);
			error_and_exit();
		}
		i++;
	}
}

void	check_for_doubles(t_parse_info *info)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (i < info->count)
	{
		num1 = info->nums[i];
		j = i + 1;
		while (j < info->count)
		{
			num2 = info->nums[j];
			if (num1 == num2)
			{
				free(info->nums);
				free(info);
				error_and_exit();
			}
			j++;
		}
		i++;
	}
}

int	*parse_int(int argc, char **argv, t_parse_info *info)
{
	char	**nums_matrix;
	int		*nums;
	int		i;
	int		j;
	int		k;

	nums = (int *)malloc(sizeof(int) * info->count);
	if (!nums)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		nums_matrix = ft_split(argv[i], ' ');
		if (!nums_matrix)
			return (NULL);
		check_int_size(nums_matrix, nums, info);
		k = 0;
		while (nums_matrix[k])
			nums[j++] = ft_atoi(nums_matrix[k++]);
		ft_free_matrix(nums_matrix);
	}
	return (nums);
}

t_parse_info	*detect_input_error(int argc, char **argv)
{
	t_parse_info	*info;

	if (argc == 1)
		exit(0);
	info = malloc(sizeof(t_parse_info));
	info->count = check_integers(argc, argv);
	if (info->count == -1)
	{
		free(info);
		error_and_exit();
	}
	info->nums = parse_int(argc, argv, info);
	if (!info->nums)
	{
		free(info);
		error_and_exit();
	}
	check_for_doubles(info);
	return (info);
}
