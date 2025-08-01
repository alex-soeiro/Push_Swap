/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/01 03:17:04 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/push_swap.h"
#include "../include/libft/include/libft.h"

int	count_numbers(char **nums)
{
	int	number_count;

	number_count = 0;
	while (nums[number_count])
		number_count++;
	return (number_count);
}

t_array	normalize(char **nums)
{
	int		i;
	t_array	middle;

	i = 0;
	middle.length = count_numbers(nums);
	middle.i_array = malloc((middle.length) * sizeof(int));
	while (i < middle.length)
		middle.i_array[i++] = ft_atoi(*(nums++));
	i = 0;
	i_merge_sort(middle);
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

int	is_ordered(t_array ordered, t_dblylst *stack)
{
	int	i;

	i = 0;
	while (i < ordered.length)
	{
		if (ordered.i_array[i++] != *(int *) stack->content)
			return (0);
		stack = stack->next;
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
	ordered = normalize(nums);
	stack_a = createstack_a(nums);
	if (is_ordered(ordered, stack_a))
		return (free(ordered.i_array), ft_dblylst_clear(stack_a), 0);
	sort(&stack_a, &stack_b);
	ft_dblylst_clear(stack_a);
	free(ordered.i_array);
}
