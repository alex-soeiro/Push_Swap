/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:57:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/21 18:32:49 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

// Description: Swap the first two elements of a stack.
void	swap(t_doublylist **stack)
{
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



/* SWAP_A

Description: Use swap function in stack 'a'

Operations:
	1. Call swap function for stack 'a' */

/* SWAP_B

Description: Use swap function in stack 'b'

Operations:
	1.Call swap function for stack 'b'; */

/* SWAP_SWAP

Description: Use swap funtion in both 'a' and 'b' stacks;

Operations:
	1. Call swap function in stack 'a';
	2. Call swap function in stack 'b'; */
