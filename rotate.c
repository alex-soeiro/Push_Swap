/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:40:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/09 19:29:33 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ROTATE

Description: Rotate the first element of a stack to be the last element of a stack;

Operations:
	1. Create a temporary pointer that's a copy of head;
	2. Create a temporary pointer that's a copy of first_node->next;
	3. Make first_node->next be same as NULL;
	4. Make last_node->next be same as first_node addres;
	5. Make head be same as second_node address; */

/* REVERSE_ROTATE

Description: Rotate the last element of a stack to be the frst element of a stack;

Operations:
	1. Create a temporary pointer that's a copy of head;
	2. Create a temporary pointer that's a copy of penultimate node->next;
	3. Make head be same as penultimate node->next;
	4. Make penultimate node->next be same as NULL;
	5. Make first_node->next be same as head; */

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
