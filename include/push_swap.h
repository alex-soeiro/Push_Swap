/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/03 18:07:28 by avieira-         ###   ########.fr       */
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

int			error_message(int error_code);
t_dblylst	*createstack_a(char **nums);
int			is_only_numbers(char **nums);
int			is_repeated_number(char **nums);
int			is_int(char **nums);
int			is_only_spaces(char *argv);
int			parse(int argc, char **argv, char ***nums);
int			is_ordered(t_array ordered, t_dblylst *stack);

// MOVEMENTS //

void		rotate(t_dblylst **stack);
void		ra(t_dblylst **stack_a, int times);
void		rb(t_dblylst **stack_b, int times);
void		rr(t_dblylst **stack_a, t_dblylst **stack_b, int times);
void		reverse_rotate(t_dblylst **stack);
void		rra(t_dblylst **stack_a, int times);
void		rrb(t_dblylst **stack_b, int times);
void		rrr(t_dblylst **stack_a, t_dblylst **stack_b, int times);
int			swap(t_dblylst **stack);
void		sa(t_dblylst **stack_a, int times);
void		sb(t_dblylst **stack_b, int times);
void		ss(t_dblylst **stack_a, t_dblylst **stack_b, int times);
int			push(t_dblylst **stack_x, t_dblylst **stack_y);
void		pa(t_dblylst **stack_a, t_dblylst **stack_b, int times);
void		pb(t_dblylst **stack_a, t_dblylst **stack_b, int times);

// SORT //

void		sort(t_dblylst **stack_a, t_dblylst **stack_b);
void		little_sort(t_dblylst **stack_a);
void		big_sort(t_dblylst **stack_a, t_dblylst **stack_b);
void		cost_reset(t_dblylst **stack);

// CALCULATE COST //

void		calculate_cost(t_dblylst **stack_a, t_dblylst **stack_b);
void		get_moves(t_dblylst *stack_a, t_dblylst **stack_b, int a_size);
void		economize(t_dblylst *stack_a, int a_size, int b_size, int eco);
void		get_bmin(t_dblylst *stack_a, t_dblylst **stack_b);
void		get_bmax(t_dblylst *stack_a, t_dblylst **stack_b);

// GET B TARGET //

void		get_btarget(t_dblylst **stack_a, t_dblylst **stack_b);
void		get_amin(t_dblylst **stack_a, t_dblylst **stack_b);
void		get_amax(t_dblylst **stack_a, t_dblylst **stack_b);

// TRANSFER A //

void		transfer_a(t_dblylst **stack_a, t_dblylst **stack_b);

// ORGANIZE //

void		organize_b(t_dblylst **stack_b);
void		organize_a(t_dblylst **stack_a);
int			get_pos(t_dblylst **stack, int biggest);
int			get_biggest(t_dblylst **stack);
int			get_smallest(t_dblylst **stack);

// TRANSFER B //

void		transfer_b(t_dblylst **stack_a, t_dblylst **stack_b);
void		ab_rrot(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst *cheap);
void		ab_rot(t_dblylst **stack_a, t_dblylst **stack_b, t_dblylst *cheap);
t_dblylst	*get_cheapest(t_dblylst **stack_a);

#endif
