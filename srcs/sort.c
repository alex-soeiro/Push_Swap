/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:15:46 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/30 01:38:24 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	cost_reset(t_dblylst **stack_a)
{
	int			size;
	t_dblylst	*stack_a_iter;	

	size = ft_dblylst_size(*stack_a);
	stack_a_iter = *stack_a;
	while (size --)
	{
		stack_a_iter->moves = 0;
		stack_a_iter = stack_a_iter->next;
	}
}

void	little_sort(t_dblylst **stack_a, t_array ordered)
{
	if (is_ordered(ordered, *stack_a))
		return ;
	// algorithm for 3 numbers or less
	return ;
}

void	big_sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered)
{
	int	a_size;

	a_size = ft_dblylst_size(*stack_a);
	if (a_size < 4)
		return (little_sort(stack_a, ordered));
	// Push B twice
	pb(stack_a, stack_b, 2);
	// Find the cheapest number (regarding stack_a movements and stack_b movements)
	while (a_size-- > 3)
	{
		calculate_cost(stack_a, stack_b);
		transfer_b(stack_a, stack_b);
		cost_reset(stack_a);
	}
	//little_sort(stack_a, ordered);

	// Rotate B until sorted
	organize_b(stack_b);
	// Push A stack_b size times
	//transfer_a(stack_a, stack_b);
}

void	sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered)
{
	int	a_size;

	a_size = ft_dblylst_size(*stack_a);
	// If stack_a size == 2 ---> SWAP A 
	if (a_size == 2)
		sa(stack_a, 1);
	// Else If stack_a size < 4 ---> little_sort
	else if (a_size == 3)
		return ;
		//little_sort(stack_a, ordered);
	// Else If stack_a size > 4 ---> big_sort
	else if (a_size > 3)
		big_sort(stack_a, stack_b, ordered);
}
