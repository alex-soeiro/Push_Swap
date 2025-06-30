/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:15:46 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/30 16:04:20 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

void	cost_reset(t_dblylst **stack)
{
	int			size;
	t_dblylst	*stack_iter;	

	size = ft_dblylst_size(*stack);
	stack_iter = *stack;
	while (size--)
	{
		stack_iter->moves = 0;
		stack_iter = stack_iter->next;
	}
}

int	get_big_a(t_dblylst **stack_a)
{
	int			i;
	int			big_a;
	t_dblylst	*stack_a_iter; i = 3; stack_a_iter = *stack_a;

	big_a = *(int *)stack_a_iter->content;
	while (i--)
	{
		if (*(int *)stack_a_iter->content > big_a)
			big_a = *(int *)stack_a_iter->content;
		stack_a_iter = stack_a_iter->next;
	}
	return (big_a);
}

void	little_sort(t_dblylst **stack_a, t_array ordered)
{
	int			big_a;

	if (is_ordered(ordered, *stack_a))
		return ;
	big_a = get_big_a(stack_a);
	if (*(int *)(*stack_a)->content == big_a)
		ra(stack_a, 1);
	else if (*(int *)(*stack_a)->next->content > big_a)
		rra(stack_a, 1);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a, 1);
}

void	big_sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered)
{
	int	a_size;
	int	b_size;

	a_size = ft_dblylst_size(*stack_a);
	if (a_size < 4)
		return (little_sort(stack_a, ordered));
	if (a_size == 4)
		pb(stack_a, stack_b, 1);
	else
		pb(stack_a, stack_b, 2);
	while (a_size-- > 3)
	{
		calculate_cost(stack_a, stack_b);
		transfer_b(stack_a, stack_b);
		cost_reset(stack_a);
	}
	organize_b(stack_b);
	b_size = ft_dblylst_size(*stack_b);
	while (b_size--)
	{
		get_btarget(stack_a, stack_b);
		transfer_a(stack_a, stack_b);
	}
}

void	sort(t_dblylst **stack_a, t_dblylst **stack_b, t_array ordered)
{
	int	a_size;

	a_size = ft_dblylst_size(*stack_a);
	if (a_size == 2)
		sa(stack_a, 1);
	else if (a_size == 3)
		little_sort(stack_a, ordered);
	else if (a_size > 3)
		big_sort(stack_a, stack_b, ordered);
}
