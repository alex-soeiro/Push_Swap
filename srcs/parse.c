/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:34:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 19:40:29 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

int	is_only_numbers(char **nums)
{
	int	i;
	int	j;
	int	num_len;

	i = 0;
	while (nums[i])
	{
		j = 0;
		num_len = ft_strlen(nums[i]);
		if (j < num_len && nums[i][j] && ft_issign(nums[i][j]))
			j++;
		while (j < num_len && ft_isdigit(nums[i][j]))
			j++;
		if (j < num_len || !ft_isdigit(nums[i][j - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_repeated_number(char **nums)
{
	int	i;
	int	j;

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

char	**split_args(char **argv, int argc)
{
	int		i;
	char	*args;
	char	*tmp;
	char	**split;

	i = 1;
	args = ft_strdup(" ");
	while (i < argc)
	{
		tmp = args;
		args = ft_strjoin(args, argv[i]);
		free (tmp);
		tmp = args;
		args = ft_strjoin(args, " ");
		free(tmp);
		i++;
	}
	split = ft_split(args, ' ');
	return (free(args), split);
}

int	is_only_spaces(char *argv)
{
	while (*argv)
		if (!ft_isspace(*argv++))
			return (0);
	return (1);
}

int	parse(int argc, char **argv, char ***nums)
{
	int		i;

	i = 1;
	if (argc == 1)
		return (1);
	while (argv[i])
		if (argv[i++][0] == '\0')
			return (error_message(2));
	i = 0;
	while (argv[i])
		if (is_only_spaces(argv[i++]))
			return (error_message(3));
	*nums = split_args(argv, argc);
	if (!is_only_numbers(*nums))
		return (ft_free_matrix(*nums), error_message(4));
	if (!ft_is_int(*nums))
		return (error_message(5));
	if (is_repeated_number(*nums))
		return (ft_free_matrix(*nums), error_message(5));
	return (0);
}
