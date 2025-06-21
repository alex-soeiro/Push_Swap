/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:40:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/21 17:51:39 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

// Rotate the first element of a stack to be the last element of a stack

void	rotate(t_doublylist **stack)
{
	*stack = (*stack)->next;
}


// Rotate the last element of a stack to be the frst element of a stack

void	reverse_rotate(t_doublylist **stack)
{
	*stack = (*stack)->prev;
}

/* ROTATE_A

Description: Use rotate function to place first element of stack 'a' to be the last element of stack 'a';

Operations:
	1. Call rotate function on stack 'a'; */

/* ROTATE_B

Description: Use rotate function to place first element of stack 'b' to be the last element of stack 'b'

Operations:
	1. Call rotate function on stack 'b'; */

/* REVERSE_ROTATE_A

Description: Use reverse_rotate function to place first element of stack 'a' to be the last element of stack 'a';

Operations:
	1. Call reverse_rotate function on stack 'a'; */

/* REVERSE_ROTATE_B

Description: Use reverse_rotate function to place first element of stack 'b' to be the last element of stack 'b';

Operations:
	1. Call reverse_rotate function on stack 'b'; */


