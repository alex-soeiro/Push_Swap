/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_btarget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 23:13:27 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/01 02:33:31 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	get_amax(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			a_size;
	int			b_content;
	t_dblylst	*stack_a_iter;

	b_content = *(int *)(*stack_b)->content;
	stack_a_iter = *stack_a;
	a_size = ft_dblylst_size(*stack_a);
	(*stack_b)->target = NULL;
	while (a_size--)
	{
		if ((*stack_b)->target == NULL
			&& *(int *)stack_a_iter->content > b_content)
			(*stack_b)->target = stack_a_iter;
		else if ((*stack_b)->target != NULL
			&& *(int *)stack_a_iter->content > b_content
			&& *(int *)stack_a_iter->content
			< *(int *)(*stack_b)->target->content)
			(*stack_b)->target = stack_a_iter;
		stack_a_iter = stack_a_iter->next;
	}
}

void	get_amin(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int			a_size;
	t_dblylst	*stack_a_iter;

	stack_a_iter = *stack_a;
	a_size = ft_dblylst_size(*stack_a);
	(*stack_b)->target = *stack_a;
	while (a_size--)
	{
		if (*(int *)(*stack_b)->target->content
			> *(int *)stack_a_iter->content)
			(*stack_b)->target = stack_a_iter;
		stack_a_iter = stack_a_iter->next;
	}
}

void	get_btarget(t_dblylst **stack_a, t_dblylst **stack_b)
{
	get_amax(stack_a, stack_b);
	if ((*stack_b)->target == NULL)
		get_amin(stack_a, stack_b);
}
