/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:04:17 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/28 23:20:52 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	transfer(t_dblylst **stack_a, t_dblylst **stack_b, int position)
{
	int	i;
	int	size;

	i = 0;
	size = ft_dblylst_size(*stack_a);
	if (position <= size / 2)
	{
		ra(stack_a, position);
	}
	else if (position > size / 2)
	{
		rra(stack_a, size - position);
	}
	pb(stack_a, stack_b, 1);
}

void	transfer_sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered)
{
	int			i;
	int			j;
	int			size;
	t_dblylst	*stack_a_iter;

	i = -1;
	size = ft_dblylst_size(*stack_a);
	while (++i < size)
	{
		j = 0;
		stack_a_iter = *stack_a;
		while (*(int *) stack_a_iter->content != ordered.i_array[i])
		{
			stack_a_iter = stack_a_iter->next;
			j++;
		}
		transfer(stack_a, stack_b, j);
	}
	i = -1;
	size = ft_dblylst_size(*stack_b) + 1;
	pa(stack_a, stack_b, size);
}
