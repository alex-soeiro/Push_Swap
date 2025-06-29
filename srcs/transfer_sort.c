/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:04:17 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/29 21:37:12 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

t_dblylst	*get_cheapest(t_dblylst **stack_a)
{
	int			a_size;
	int			moves;
	t_dblylst	*stack_a_iter;
	t_dblylst	*cheapest;

	if (stack_a_iter->moves == 1)
		return (stack_a_iter);
	cheapest = stack_a_iter;
	stack_a_iter = stack_a;
	a_size = ft_dblylst_size(stack_a);
	while (size--)
	{
		if (stack_a_iter->moves < cheapest->moves)
			cheapest = stack_a_iter;
		stack_a_iter = stack_a->next;
	}
	return (cheapest);
}

void	rotate_top(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst cheapest)
{
	if (cheapest->pos <= cheapest->target_pos)
	{
		rr(stack_a, stack_b, cheapest->pos);
		rb(stack_b, cheapest->target_pos - cheapest->pos);
	}
	else
	{
		rr(stack_a, stack_b, cheapest->target_pos);
		ra(stack_a, cheapest->pos - cheapest->target_pos);
	}
}

void	rotate_bottom(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst cheapest)
{
	int	a_size;
	int	b_size;
	int a_moves;
	int	b_moves;

	a_size = ft_dblylst_size(stack_a);
	b-size = ft_dblylst_size(stack_b);
	a_moves = a_size - cheapest->pos;
	b_moves = b_size - cheapest->target_pos;
	if (a_moves <= b_moves)
	{
		rrr(stack_a, stack_b, a_moves);
		rb(stack_b, b_moves - a_moves);
	}
	else
	{
		rrr(stack_a, stack_b, b_moves);
		ra(stack_a, a_moves - b_moves);
	}
}

void	transfer(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			a_pos;
	int			b_pos;
	int			size;
	t_dblylst	*cheapest;

	size = ft_dblylst_size(*stack_a);
	cheapest = get_cheapest(stack_a);	
	if (cheapest->pos <= size / 2 
			&& cheapest->target_pos <= size / 2 )
		rotate_top(stack_a, stack_b, cheapest);
	else if (cheapest->pos > size / 2
			&& cheapest->target_pos > size / 2)
		rotate_bottom(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b, 1);
}
