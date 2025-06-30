/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_btarget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 23:13:27 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/06/30 13:09:34 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	get_amax(t_dblylst **stack_a, t_dblylst *stack_b)
{
	int			a_size;
	t_dblylst	*stack_a_iter;

	stack_a_iter = *stack_a_iter;
	a_size = ft_dblylst_size(*stack_a);
	stack_b->target = NULL;
	stack_b->target_pos = 0;
	while (a_size--)
	{
		if (stack_b->target == NULL
			&& *(int *)stack_a_iter->content > *(int *)stack_b->content)
			stack_b->target = stack_a_iter;
		else if (stack_b->target != NULL
			&& *(int *)stack_a_iter->content > *(int *)stack_b->content
			&& *(int *)stack_a_iter->content < *(int *)stack_b->target->content)
			< *(int *)stack_b->target->content
			stack_b->target = stack_a_iter;
		stack_b->target_pos++;
		stack_a_iter = stack_a_iter->next;
	}
}

void	get_amin(t_dblylst **stack_a, t_dblylst *stack_b)
{
	int			a_size;
	t_dblylst	*stack_a_iter;

	stack_a_iter = *stack_b;
	a_size = ft_dblylst_size(*stack_a);
	stack_b->target = *stack_a;
	stack_b->target_pos = 0;
	while (a_size--)
	{
		if (*(int *)stack_b->target->content > *(int *)stack_a_iter->content)
			stack_b->target = stack_a_iter;
		stack_b->target_pos++;
		stack_a_iter-> = stack_a_iter;
	}
}

void	get_btarget(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			b_size;
	t_dblylst	*stack_b_iter;

	b_size = ft_dblylst_size(*stack_b);
	stack_b_iter = *stack_b;
	while (b_size--)
	{
		get_amax(stack_b_iter, stack_b);
		if (stack_b_iter->target == NULL)
			get_bmax(stack_b_iter, stack_a);
		stack_b_iter = stack_b_iter->next;
	}
}
