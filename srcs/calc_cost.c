/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:02:39 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/01 01:59:27 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	get_bmax(t_dblylst *stack_a, t_dblylst **stack_b)
{
	int			b_size;
	t_dblylst	*stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	stack_a->target = *stack_b;
	while (b_size--)
	{
		if (*(int *)stack_a->target->content < *(int *)stack_b_iter->content)
			stack_a->target = stack_b_iter;
		stack_b_iter = stack_b_iter->next;
	}
}

void	get_bmin(t_dblylst *stack_a, t_dblylst **stack_b)
{
	int			b_size;
	t_dblylst	*stack_b_iter;

	stack_b_iter = *stack_b;
	b_size = ft_dblylst_size(*stack_b);
	stack_a->target = NULL;
	while (b_size--)
	{
		if (stack_a->target == NULL
			&& *(int *)stack_b_iter->content < *(int *)stack_a->content)
			stack_a->target = stack_b_iter;
		else if (stack_a->target != NULL
			&& *(int *)stack_b_iter->content < *(int *)stack_a->content
			&& *(int *)stack_b_iter->content > *(int *)stack_a->target->content)
			stack_a->target = stack_b_iter;
		stack_b_iter = stack_b_iter->next;
	}
}

void	economize(t_dblylst *stack_a, int a_size, int b_size, int eco)
{
	if (eco == 1)
	{
		if (stack_a->pos > stack_a->target_pos)
			stack_a->moves = stack_a->pos;
		else
			stack_a->moves = stack_a->target_pos;
	}
	else if (eco == 2)
	{
		if (a_size - stack_a->pos > b_size - stack_a->target_pos)
			stack_a->moves = a_size - stack_a->pos;
		else
			stack_a->moves = b_size - stack_a->target_pos;
	}
}

void	get_moves(t_dblylst *stack_a, t_dblylst **stack_b, int a_size)
{
	int	b_size;

	b_size = ft_dblylst_size(*stack_b);
	if (stack_a->pos <= a_size / 2
		&& stack_a->target_pos <= b_size / 2)
		economize(stack_a, a_size, b_size, 1);
	else if (stack_a->pos > a_size / 2
		&& stack_a->target_pos > b_size / 2)
		economize(stack_a, a_size, b_size, 2);
	else if (stack_a->pos <= a_size / 2 && stack_a->target_pos > b_size / 2)
		stack_a->moves = stack_a->target_pos + b_size - stack_a->target_pos;
	else if (stack_a->pos > a_size / 2 && stack_a->target_pos <= b_size / 2)
		stack_a->moves = a_size - stack_a->pos + stack_a->target_pos;
}

void	calculate_cost(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			i;
	int			a_size;
	int			target_content;
	t_dblylst	*stack_a_iter;

	i = 0;
	a_size = ft_dblylst_size(*stack_a);
	stack_a_iter = *stack_a;
	while (i < a_size)
	{
		stack_a_iter->pos = i++;
		get_bmin(stack_a_iter, stack_b);
		if (stack_a_iter->target == NULL)
			get_bmax(stack_a_iter, stack_b);
		target_content = *(int *) stack_a_iter->target->content;
		stack_a_iter->target_pos = get_pos(stack_b, target_content);
		get_moves(stack_a_iter, stack_b, a_size);
		stack_a_iter = stack_a_iter->next;
	}
}
