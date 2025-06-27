/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:40:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/25 18:20:47 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	rotate(t_dblylst **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_dblylst **stack_a)
{
	if (*stack_a == NULL)
		return ;
	rotate(stack_a);
	ft_printstr(RA);
}

void	rb(t_dblylst **stack_b)
{
	if (*stack_b == NULL)
		return ;
	rotate(stack_b);
	ft_printstr(RB);
}

void	rr(t_dblylst **stack_a, t_dblylst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	if (*stack_a || *stack_b)
		ft_printstr(RR);
}
