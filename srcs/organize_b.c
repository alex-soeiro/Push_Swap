/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:27:30 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/06/30 01:04:40 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

int	get_biggest(t_dblylst **stack_b)
{
	int			b_size;
	int			biggest;
	t_dblylst	*stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	biggest = *(int *) stack_b_iter->content;
	while (b_size--)
	{
		if (*(int *) stack_b_iter->content > biggest)
			biggest = *(int *) stack_b_iter->content;
		stack_b_iter = stack_b_iter->next;
	}
	return (biggest);
}

int	get_pos(t_dblylst **stack_b, int biggest)
{
	int			pos;
	int			b_size;
	t_dblylst	*stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	pos = 0;
	while (++pos < b_size)
	{
		if (*(int *) stack_b_iter->content == biggest)
			return (pos);
		stack_b_iter = stack_b_iter->next;
	}
	return (pos);
}

void	organize_b(t_dblylst **stack_b)
{
	int	b_size;
	int	biggest;
	int	biggest_pos;

	biggest = get_biggest(stack_b);
	b_size = ft_dblylst_size(*stack_b);
	biggest_pos = get_pos(stack_b, biggest);
	if (biggest_pos <= b_size / 2)
		rb(stack_b, biggest_pos);
	else
		rrb(stack_b, b_size - biggest_pos);
}
