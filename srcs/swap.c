/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:57:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/02 00:13:38 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

int	swap(t_dblylst **stack)
{
	int		size;
	t_tmp	tmp;

	size = ft_dblylst_size(*stack);
	if (size == 0 || size == 1)
		return (size);
	if (size == 2)
	{
		*stack = (*stack)->next;
		return (size);
	}
	tmp.n_1 = (*stack)->prev;
	tmp.n_2 = (*stack);
	tmp.n_3 = (*stack)->next;
	tmp.n_4 = (*stack)->next->next;
	(*stack)->next->prev = tmp.n_1;
	(*stack)->next->next = tmp.n_2;
	(*stack)->prev->next = tmp.n_3;
	(*stack)->prev->prev = tmp.n_2;
	(*stack)->next = tmp.n_4;
	(*stack)->prev = tmp.n_3;
	(*stack) = tmp.n_3;
	return (size);
}

void	sa(t_dblylst **stack_a, int times)
{
	while (times--)
	{
		if (swap(stack_a))
			ft_printstr(SA);
	}
}

void	sb(t_dblylst **stack_b, int times)
{
	while (times--)
	{
		if (swap(stack_b) > 0)
			ft_printstr(SB);
	}
}

void	ss(t_dblylst **stack_a, t_dblylst **stack_b, int times)
{
	while (times--)
	{
		if (swap(stack_a) > 1 || swap(stack_b) > 1)
			ft_printstr(SS);
	}
}
