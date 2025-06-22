/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/22 04:08:12 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

// Description: Push the top element of stack 'x' to stack 'y'.
void	push(t_doublylist **stack_x, t_doublylist **stack_y)
{
	t_doublylist	*tmp1;
	t_doublylist	*tmp2;
	t_doublylist	*tmp3;
	t_doublylist	*tmp4;
	t_doublylist	*tmp5;

	tmp1 = (*stack_x)->next;
	tmp2 = (*stack_x)->prev;
	tmp3 = (*stack_y)->prev;
	tmp4 = (*stack_x);
	tmp5 = (*stack_y);
	(*stack_x)->prev->next = tmp1;
	(*stack_x)->next->prev = tmp2;
	(*stack_x)->prev = tmp3;
	(*stack_x)->next = tmp5;
	(*stack_x) = tmp1;
	(*stack_y)->prev->next = tmp4;
	(*stack_y)->prev = tmp4;
	(*stack_y) = tmp4;
}



/* PUSH_A

Description: Use push function to stack 'a';

Operations:
	1. Call push function to stack 'a'; */

/* PUSH_B

Decription: Use push function to stack 'b';

Operations:
	1. Call push function to stack 'b'; */
