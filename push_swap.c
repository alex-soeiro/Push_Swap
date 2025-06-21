/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/21 16:30:27 by avieira-         ###   ########.fr       */
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
		// check while theres a sign or multiple signs
		while (j < num_len && nums[i][j] && ft_issign(nums[i][j]))
			j++;
		// check while if theres a number
		while (j < num_len && ft_isdigit(nums[i][j]))
			j++;
		// if theres a char other than a number
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
			if (!ft_strcmp(nums[i], nums[j++]))
				return (0);
		i++;
	}
	return (1);
}

int	is_int(char **nums)
{
	while (*nums)
	{
		if (ft_atol(*nums) > INT_MAX || ft_atol(*(nums++)) < INT_MIN)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				i;
	char			**nums;
	t_doublylist	*stack_a;
	t_doublylist	*stack_a_iter;

	i = 0;
	// if no arguments given
	if (argc == 1)
		return (error_message(1));

	// if arguments given
	nums = split_args(argv, argc);

	// Parse the arguments given
	if (!is_only_numbers(nums))
		return (ft_free_matrix(nums), error_message(2));

	// Check if every number is unique
	if (!is_repeated_number(nums))
		return (ft_free_matrix(nums), error_message(3));

	// Check if every number is within int range
	if (!is_int(nums))
		return (error_message(4));

	// DEBUG: print split nums
	while (nums[i])
		ft_printf("%s\n", nums[i++]);

	// Create stack a
	stack_a = createstack_a(nums);
	stack_a_iter = stack_a;

	// DEBUG: Print stack a
	while (stack_a_iter->next != stack_a)
	{
		ft_printf("%i, ", *(int *) stack_a_iter->content);
		stack_a_iter = stack_a_iter->next;
	}
	ft_printf("%i\n", *(int *) stack_a_iter->content);

	// Free stack a;
	ft_dblylst_clear(stack_a);
}
/*
   int	main(int argc, char **argv)
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
