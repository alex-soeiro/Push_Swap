/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:57:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/24 17:07:43 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

void	swap(t_dblylst **stack)
{
	int		size;
	t_tmp	tmp;

	size = ft_dblylst_size(*stack);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
	{
		*stack = (*stack)->next;
		return ;
	}
	tmp.n_1 = (*stack)->prev;
	tmp.n_2 = (*stack);
	tmp.n_3 = (*stack)->next;
	tmp.n_4 = (*stack)->next->next;
	(*stack)->next->prev = tmp.n_1;
	(*stack)->next->next = tmp.n_2;
	(*stack)->prev->next = tmp.n_3;
	(*stack)->next = tmp.n_4;
	(*stack)->prev = tmp.n_3;
	(*stack) = tmp.n_3;
}

void	swap_swap(t_dblylst **stack_a, t_dblylst **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
