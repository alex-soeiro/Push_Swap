/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:34:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/24 20:01:35 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

int is_only_numbers(char **nums)
{
	int i;
	int j;
	int num_len;

	i = 0;
	while (nums[i])
	{
		j = 0;
		num_len = ft_strlen(nums[i]);
		while (j < num_len && nums[i][j] && ft_issign(nums[i][j]))
			j++;
		while (j < num_len && ft_isdigit(nums[i][j]))
			j++;
		if (j < num_len || !ft_isdigit(nums[i][j - 1]))
			return (0);
		i++;
	}
	return (1);
}

int is_repeated_number(char **nums)
{
	int i;
	int j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		while (j < i)
			if (ft_atol(nums[i]) == ft_atol(nums[j++]))
				return (1);
		i++;
	}
	return (0);
}

int is_int(char **nums)
{
	while (*nums)
	{
		if (ft_atol(*nums) > INT_MAX || ft_atol(*(nums++)) < INT_MIN)
			return (0);
	}
	return (1);
}

int is_only_spaces(char *argv)
{
	while (*argv)
		if (!ft_isspace(*argv++))
			return(0);
	return (1);
}

int parsing(char **nums, char **argv)
{
	int				i;
	char			**nums;
	t_dblylst	*stack_a;
	t_dblylst	*stack_b;

	i = 1;
	stack_b = NULL;
	// if no arguments given
	if (argc == 1)
		return (0);

	// if at least one argument is empty
	while (argv[i])
		if (argv[i++][0] == '\0')
			return (error_message(1));
	i = 0;
	// if at least one argument is only spaces
	while (argv[i])
		if (is_only_spaces(argv[i++]))
			return (error_message(1));
	i = 0;
	while (argv[i])
	{
		if (is_only_spaces(argv[i++]))
			return (error_message(1));
	}
	i = 0;

	// if arguments given
	nums = split_args(argv, argc);

	// Parse the arguments given
	if (!is_only_numbers(nums)) return (ft_free_matrix(nums), error_message(2));

	// Check if every number is within int range
	if (!is_int(nums))
		return (error_message(4));

	// Check if every number is unique
	if (is_repeated_number(nums))
		return (ft_free_matrix(nums), error_message(3));
}

