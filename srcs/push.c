/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:15:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/25 18:32:38 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	push_to_loaded(t_dblylst **stack_x, t_dblylst **stack_y)
{
	t_tmp	tmp;

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
}

void	push_to_empty(t_dblylst **stack_x, t_dblylst **stack_y)
{
	t_tmp	tmp;

	tmp.n_1 = (*stack_x)->next;
	tmp.n_2 = (*stack_x)->prev;
	tmp.n_3 = (*stack_x);
	(*stack_x)->prev->next = tmp.n_1;
	(*stack_x)->next->prev = tmp.n_2;
	(*stack_x) = tmp.n_1;
	(*stack_y) = tmp.n_3;
	(*stack_y)->prev = tmp.n_3;
	(*stack_y)->next = tmp.n_3;
}

int	push(t_dblylst **stack_x, t_dblylst **stack_y)
{
	int		x_size;
	int		y_size;

	x_size = ft_dblylst_size((*stack_x));
	y_size = ft_dblylst_size((*stack_y));
	if (x_size == 0)
		return (x_size);
	if (y_size == 0)
		push_to_empty(stack_x, stack_y);
	else
		push_to_loaded(stack_x, stack_y);
	if (x_size == 1)
		(*stack_x) = NULL;
	return (x_size);
}

void	pa(t_dblylst **stack_a, t_dblylst **stack_b)
{
	if (push(stack_a, stack_b))
		ft_printstr(PA);
}

void	pb(t_dblylst **stack_a, t_dblylst **stack_b)
{
	if (push(stack_b, stack_a))
		ft_printstr(PB);
}
