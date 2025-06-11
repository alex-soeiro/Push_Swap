/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/09 15:55:52 by avieira-         ###   ########.fr       */
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
		printf("%i", middle.array[i++]);
}
