/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/22 20:41:23 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

// Description: Push the top element of stack 'x' to stack 'y'.
void	push(t_doublylist **stack_x, t_doublylist **stack_y)
{
	int		size;
	t_tmp	tmp;

	size = ft_dblylst_size((*stack_x));
	if (size == 0)
		return ;
	tmp.n_1 = (*stack_x)->next;
	tmp.n_2 = (*stack_x)->prev;
	tmp.n_3 = (*stack_y)->prev;
	tmp.n_4 = (*stack_x);
	tmp.n_5 = (*stack_y);
	(*stack_x)->prev->next = tmp.n_1;
	(*stack_x)->next->prev = tmp.n_2;
	(*stack_x)->prev = tmp.n_3;
	(*stack_x)->next = tmp.n_5;
	(*stack_y)->prev->next = tmp.n_4;
	(*stack_y)->prev = tmp.n_4;
	(*stack_x) = tmp.n_1;
	(*stack_y) = tmp.n_4;
	if (size == 1)
		(*stack_x) = NULL;
}



/* PUSH_A

Description: Use push function to stack 'a';

Operations:
1. Call push function to stack 'a'; */

/* PUSH_B

Decription: Use push function to stack 'b';

Operations:
1. Call push function to stack 'b'; */
