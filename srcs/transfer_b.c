/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:04:17 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/30 01:51:18 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

t_dblylst	*get_cheapest(t_dblylst **stack_a)
{
	int			a_size;
	t_dblylst	*stack_a_iter;
	t_dblylst	*cheapest;

	stack_a_iter = *stack_a;
	cheapest = stack_a_iter;
	a_size = ft_dblylst_size(*stack_a);
	if (stack_a_iter->moves == 1)
		return (stack_a_iter);
	while (a_size--)
	{
		if (stack_a_iter->moves < cheapest->moves)
			cheapest = stack_a_iter;
		stack_a_iter = stack_a_iter->next;
	}
	return (cheapest);
}

void	ab_rot(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst *cheap)
{
	if (cheap->pos <= cheap->target_pos)
	{
		rr(stack_a, stack_b, cheap->pos);
		rb(stack_b, cheap->target_pos - cheap->pos);
	}
	else
	{
		rr(stack_a, stack_b, cheap->target_pos);
		ra(stack_a, cheap->pos - cheap->target_pos);
	}
}

void	ab_rrot(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst *cheap)
{
	int	a_size;
	int	b_size;
	int	a_moves;
	int	b_moves;

	a_size = ft_dblylst_size(*stack_a);
	b_size = ft_dblylst_size(*stack_b);
	a_moves = a_size - cheap->pos;
	b_moves = b_size - cheap->target_pos;
	if (a_moves <= b_moves)
	{
		rrr(stack_a, stack_b, a_moves);
		rrb(stack_b, b_moves - a_moves);
	}
	else
	{
		rrr(stack_a, stack_b, b_moves);
		rra(stack_a, a_moves - b_moves);
	}
}

void	transfer_b(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			size;
	t_dblylst	*cheapest;

	size = ft_dblylst_size(*stack_a);
	cheapest = get_cheapest(stack_a);
	if (cheapest->pos <= size / 2
		&& cheapest->target_pos <= size / 2)
		ab_rot(stack_a, stack_b, cheapest);
	else if (cheapest->pos > size / 2
		&& cheapest->target_pos > size / 2)
		ab_rrot(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b, 1);
}
