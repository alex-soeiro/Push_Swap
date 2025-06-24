/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/24 17:29:20 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../include/libft/include/libft.h"

typedef struct s_tmp
{
	t_dblylst	*n_1;
	t_dblylst	*n_2;
	t_dblylst	*n_3;
	t_dblylst	*n_4;
	t_dblylst	*n_5;
	t_dblylst	*n_6;
	t_dblylst	*n_7;
	t_dblylst	*n_8;
}	t_tmp;

int				error_message(int error_code);
t_dblylst		*createstack_a(char **nums);

// MOVEMENTS //

void			rotate(t_dblylst **stack);
void			reverse_rotate(t_dblylst **stack);
void			rotate_rotate(t_dblylst **stack_a, t_dblylst **stack_b);
void			reverse_rotate_rotate(t_dblylst **stack_a, t_dblylst **stack_b);
void			swap(t_dblylst **stack);
void			swap_swap(t_dblylst **stack_a, t_dblylst **stack_b);
void			push(t_dblylst **stack_x, t_dblylst **stack_y);

#endif
