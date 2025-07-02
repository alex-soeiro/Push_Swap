/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:27:30 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/02 02:02:30 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	organize_b(t_dblylst **stack_b)
{
	int	b_size;
	int	biggest;
	int	biggest_pos;

	biggest = get_biggest(stack_b);
	b_size = ft_dblylst_size(*stack_b);
	biggest_pos = get_pos(stack_b, biggest);
	if (biggest_pos <= b_size / 2)
		rb(stack_b, biggest_pos);
	else
		rrb(stack_b, b_size - biggest_pos);
}

void	organize_a(t_dblylst **stack_a)
{
	int			a_size;
	int			smallest;
	int			smallest_pos;
	
	smallest = get_smallest(stack_a);
	a_size = ft_dblylst_size(*stack_a);
	smallest_pos = get_pos(stack_a, smallest);
	if (smallest_pos <= a_size / 2)
		ra(stack_a, smallest_pos);
	else
		rra(stack_a, a_size - smallest_pos);
}
