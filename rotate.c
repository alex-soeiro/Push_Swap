/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:40:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/23 18:21:18 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

void	rotate(t_dblylst **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
}

void	reverse_rotate(t_dblylst **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rotate_rotate(t_dblylst **stack_a, t_dblylst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_rotate(t_dblylst **stack_a, t_dblylst **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
