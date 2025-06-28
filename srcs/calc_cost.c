/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:02:39 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/28 23:58:37 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	get_max(t_dblylst *stack_a, t_dblylst **stack_b)
{
	int			b_size;
	t_dblylst 	stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	stack_a->target = *(int *) stack_b->content;
	stack_a->target_pos = 0;
	while (b_size--)
	{
		if (stack_a->target < *(int *) stack_b->content)
			stack_a->target = *(int *) stack_b->content;
		stack_b_iter = stack_b_iter->next;
		stack_a->target_pos++;
	}
}

void	get_min(t_dblylst *stack_a, t_dblylst **stack_b)
{
	int			b_size;
	t_dblylst	stack_a_iter;
	t_dblylst	stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	stack_a->target = NULL;
	stack_a->target_pos = 0;
	while (b_size--)
	{
		if stack_a->target == NULL
				&& *(int *) stack_b_iter->content < *(int *) stack_a->content)
			(*stack_a)->target = stack_b_iter->content;
		else if (*(int *) stack_b_iter->content > stack_a->target 
				&& *(int *) stack_b_iter->content < *(int *) stack_a->content)
			stack_a->target = stack_b_iter->content;
		stack_b_iter = stack_b_iter->next;
		stack_a->target_pos++;
	}
}

void	get_moves(t_dblylst *stack_a, t_dblylst **stack_b)
{
	int	a_size;
	int	b_size;

	a_size = ft_dblylst_size(stack_a);
	b_size = ft_dblylst_size(*stack_b);
	if (stack_a->pos <= a_size / 2 && stack_a->target_pos <= b_size / 2)
	{
		if (stack_a->pos >= stack_a->target_pos)
			stack_a->moves = stack_a->pos;
		else
			stack_a->moves = stack_a->target_pos;
	}
}

void	get_target(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			i;
	int			a_size;
	t_dblylst	*stack_a_iter;
	
	i = 0;
	a_size = ft_dblylst_size(*stack_a);
	stack_a_iter = *stack_a;
	while (a_size--)
	{
		stack_a_iter->pos = i++;
		get_min(stack_a_iter, stack_b);
		if (stack_a_iter->target == NULL)
			get_max(stack_b);
		get_moves(stack_a_iter, stack_b);
		stack_a_iter = stack_a_iter->next;
	}
}

void	calculate_cost(t_dblylst **stack_a, t_dblylst **stack_b)
{
	get_target(stack_a, stack_b);
	get_moves(stack_a, stack_b);
}
