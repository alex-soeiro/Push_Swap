/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/26 17:36:27 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../include/libft/include/libft.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

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

// PARSING //

int				error_message(int error_code);
t_dblylst		*createstack_a(char **nums);
int				is_only_numbers(char **nums);
int				is_repeated_number(char **nums);
int				is_int(char **nums);
int				is_only_spaces(char *argv);
int				parse(int argc, char **argv, char ***nums);

// MOVEMENTS //

void			rotate(t_dblylst **stack);
void			ra(t_dblylst **stack_a);
void			rb(t_dblylst **stack_b);
void			rr(t_dblylst **stack_a, t_dblylst **stack_b);
void			reverse_rotate(t_dblylst **stack);
void			rra(t_dblylst **stack_a);
void			rrb(t_dblylst **stack_b);
void			rrr(t_dblylst **stack_a, t_dblylst **stack_b);
int				swap(t_dblylst **stack);
void			sa(t_dblylst **stack_a);
void			sb(t_dblylst **stack_b);
void			ss(t_dblylst **stack_a, t_dblylst **stack_b);
int				push(t_dblylst **stack_x, t_dblylst **stack_y);
void			pa(t_dblylst **stack_a, t_dblylst **stack_b);
void			pb(t_dblylst **stack_a, t_dblylst **stack_b);

// TRANSFER_SORT //

void	transfer(t_dblylst **stack_a, t_dblylst **stack_b, int size, int position);
void	transfer_sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered);

#endif
