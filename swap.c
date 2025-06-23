/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:57:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/23 17:53:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

void	swap(t_doublylist **stack)
{
	int	size;

	size = ft_dblylst_size(*stack);
	if (size == 0 || size == 1)
		return ;
	t_doublylist	*tmp1;
	t_doublylist	*tmp2;
	t_doublylist	*tmp3;
	t_doublylist	*tmp4;

	tmp1 = (*stack)->prev;
	tmp2 = (*stack);
	tmp3 = (*stack)->next;
	tmp4 = (*stack)->next->next;
	(*stack)->next->prev = tmp1;
	(*stack)->next->next = tmp2;
	(*stack)->prev->next = tmp3;
	(*stack)->next = tmp4;
	(*stack)->prev = tmp3;
	(*stack) = tmp3;
}

void	swap_swap(t_doublylist **stack_a, t_doublylist **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
