/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/26 18:17:40 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/push_swap.h"
#include "../include/libft/include/libft.h"

t_array	normalize(int argc, char **argv)
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
	return (middle);
}

void	print_stack(t_dblylst *stack)
{
	t_dblylst	*stack_iter;

	stack_iter = stack;
	if (!stack)
		return ;
	while (stack_iter->next != stack)
	{
		ft_printf("%i, ", *(int *) stack_iter->content);
		stack_iter = stack_iter->next;
	}
	ft_printf("%i\n", *(int *) stack_iter->content);
}

int	is_ordered(t_array ordered, t_dblylst *stack_a)
{
	int	i;

	i = 0;
	while (i < ordered.length)
	{
		if (ordered.array[i++] != *(int *) stack_a->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int			parsing_ko;
	char		**nums;
	t_array		ordered;
	t_dblylst	*stack_a;
	t_dblylst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing_ko = parse(argc, argv, &nums);
	if (parsing_ko)
		return (parsing_ko);
	ordered = normalize(argc, argv);
	stack_a = createstack_a(nums);
	if (is_ordered(ordered, stack_a))
	{
		print_stack(stack_a);
		return (free(ordered.array), ft_dblylst_clear(stack_a), 0);
	}
	transfer_sort(&stack_a, &stack_b, ordered);
	print_stack(stack_a);
	ft_dblylst_clear(stack_a);	
	free(ordered.array);
}
