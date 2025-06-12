/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/12 16:15:20 by avieira-         ###   ########.fr       */
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
char	*generate_stack(char **numbers)
{
} */

void	arg_parse(char **arg)
{
	/* if a character is found print "Error\n"
	 *
	 * ./push_swap 1 3 dog 35 80 -3
	 *
	 * ./push_swap a
	 *
	 * ./push_swap 1 2 3 5 67b778 947
	 *
	 * .push_swap " 12 4 6 8 54fhd 4354"
	 *
	 * ./push_swap 1--    45 32 */
	
	/* if a double number is found, print "Error\n" */
}

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

	i = 0;
	while (numbers[i])
	{
		// ignore spaces

		// if theres a char other than a number and a sign
			// return error

		// check if theres a sign or multiple signs
		
		// if theres a char other than a number and a sign
			// return error

		// check if theres a number

		// if theres a char other than a number and a sign
			// return error
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**numbers;

	i = 0;
	if (argc == 1)
	{
		ft_printf("No arguments given");
		return (1);
	}
	if (argc > 1)
	{
		numbers = split_args(argv, argc);
		while (numbers[i])
		{
			ft_printf("%s, ", numbers[i]);
			free(numbers[i++]);
		}
		free(numbers);
	}
	// Parse the argument given
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
