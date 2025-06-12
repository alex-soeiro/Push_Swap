/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/12 17:48:44 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/push_swap.h"
#include "include/libft/include/libft.h"

/* PUSH SWAP

Operations:
	1. Receive "stack a";
	2. TO BE DECIDED */

/* MAIN

Operations:
	1. Create "stack a".
	2. Call push_swap sorting function. */

/*
char	*generate_stack(char **nums)
{
} */

char	**split_args(char **argv, int argc)
{
	int		i;
	char	*args;
	char	*tmp;
	char	**split;

	i = 0;
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
	return(free(args), split);
}

int	is_only_numbers(char **)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i])
	{
		// if theres a char other than a number and a sign
			// return error
		if (nums[i][j] != '-' && nums[i][j] != '+' && !ft_isdigit(nums[i][j])
				

		// check while theres a sign or multiple signs

		// check if theres a number
		if (!ft_isdigit(nums[i][j]))

		// if theres a char other than a number and a sign
			// return error
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**nums;

	i = 0;
	if (argc == 1)
	{
		ft_printf("No arguments given");
		return (1);
	}
	if (argc > 1)
	{
		nums = split_args(argv, argc);
		while (nums[i])
		{
			ft_printf("%s, ", nums[i]);
			free(nums[i++]);
		}
		free(nums);
	}
	// Parse the argument given
	if (!is_only_numbers(nums))
		return ("Error\n");
}

/* int	main(int argc, char **argv)
   {
   int		i;
   int		j;
   t_array	middle;

   i = 1;
   j = 0;
   middle.length = argc - 1;
   middle.array = malloc((argc - 1) * sizeof(int));
   while (i < argc)
   middle.array[j++] = ft_atoi(argv[i++]);
   i = 0;
   merge_sort(middle);
   while (i < argc - 1)
   printf("%i, ", middle.array[i++]);
   free(middle.array);
   }*/
