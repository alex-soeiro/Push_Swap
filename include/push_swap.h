/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/22 03:47:03 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "../include/libft/include/libft.h"

int				error_message(int error_code);
t_doublylist	*createstack_a(char **nums);

// MOVEMENTS //

void	rotate(t_doublylist **stack);
void	reverse_rotate(t_doublylist **stack);
void	swap(t_doublylist **stack);
void	push(t_doublylist **stack_x, t_doublylist **stack_y);

#endif
