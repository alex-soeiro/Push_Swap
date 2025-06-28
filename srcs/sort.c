/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:15:46 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/28 21:38:05 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	transfer(t_dblylst **stack_a, t_dblylst **stack_b)
{
	if (stack_a->position <= size / 2)
		ra(stack_a, position);
	else if (stack_a->position > size / 2)
		rra(stack_a, size - stack_a->position);
	pb(stack_a, stack_b, 1);
}

void	little_sort(t_dblylst **stack_a)
{
	if is_ordered(stack_b);
		return ;
	// algorithm for 3 numbers or less
	
	return ;	
}

void	big_sort(t_dblylst **stack_a, t_dblylst **stack_b, int a_size)
{
	int	a_size;

	a_size = ft_dblylst_size(stack_a);
	if (a_size < 4)
		return (little_sort(stack_a));
	// Push B twice
	pb(stack_a, stack_b, 2);
	// Find the cheapest number (regarding stack_a movements and stack_b movements)
	while (a_size-- > 3)
	{
		calculate_cost(stack_a, stack_b);
		// Move the cheapest number
	}
	little_sort(stack_a);
	// Rotate B until sorted
	// Push A stack_b size times
}

void	sort(t_dblylst **stack_a, t_dblylst **stack_b)
{
	int	a_size;

	a_size = ft_dblylst_size(*stack_a);
	// If stack_a size == 2 ---> SWAP A 
	if (a_size == 2) sa(stack_a);
	// Else If stack_a size < 4 ---> little_sort
	else if (a_size == 3)
		little_sort(stack_a);
	// Else If stack_a size > 4 ---> big_sort
	else if (a_size > 3)
		big_sort(stack_a, stack_b);
}
