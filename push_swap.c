/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/11 20:59:21 by avieira-         ###   ########.fr       */
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

char	*generate_stack(char **numbers)
{
}

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

int	main(int argc, char **argv)
{
	int		i;
	char	space;
	char	*args;
	char	*numbers;
	char	*tmp;

	// PLACE THIS IN A SEPERATE FUNCTION (join_args)
	i = 1;
	space = ' ';
	args = ft_strdup(" ");;
	numbers = "";
	if (argc == 1)
		ft_printf("No arguments given");
	
	if (argc > 2)
	{
		while (i < argc)
		{
			tmp = args;
			args = ft_strjoin(args, space);
			free (tmp);
			tmp = args;
			args = ft_strjoin(args, argv[i]);
			free(tmp);
			i++;
		}
		numbers = ft_split(numbers, space);
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
