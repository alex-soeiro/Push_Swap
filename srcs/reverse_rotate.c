/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:31:02 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/28 23:01:22 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	reverse_rotate(t_dblylst **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_dblylst **stack_a, int times)
{
	while (times--)
	{
		if (*stack_a == NULL)
			return ;
		reverse_rotate(stack_a);
		ft_printstr(RRA);
	}
}

void	rrb(t_dblylst **stack_b, int times)
{
	while (times--)
	{
		if (*stack_b == NULL)
			return ;
		reverse_rotate(stack_b);
		ft_printstr(RRB);
	}
}

void	rrr(t_dblylst **stack_a, t_dblylst **stack_b, int times)
{
	while (times--)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		if (*stack_a || *stack_b)
			ft_printstr(RRR);
	}
}
