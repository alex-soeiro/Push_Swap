/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:27:30 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/30 18:55:04 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/include/libft.h"
#include "../include/push_swap.h"

int	get_biggest(t_dblylst **stack)
{
	int			size;
	int			biggest;
	t_dblylst	*stack_iter;

	stack_iter = *stack;
	size = ft_dblylst_size(*stack);
	biggest = *(int *) stack_iter->content;
	while (size--)
	{
		if (*(int *) stack_iter->content > biggest)
			biggest = *(int *) stack_iter->content;
		stack_iter = stack_iter->next;
	}
	return (biggest);
}

int	get_smallest(t_dblylst **stack)
{
	int			size;
	int			smallest;
	t_dblylst	*stack_iter;

	stack_iter = *stack;
	size = ft_dblylst_size(*stack);
	smallest = *(int *) stack_iter->content;
	while (size--)
	{
		if (*(int *) stack_iter->content < smallest)
			smallest = *(int *) stack_iter->content;
		stack_iter = stack_iter->next;
	}
	return (smallest);
}

int	get_pos(t_dblylst **stack, int content)
{
	int			pos;
	int			size;
	t_dblylst	*stack_iter;

	stack_iter = *stack;
	size = ft_dblylst_size(*stack);
	pos = 0;
	while (pos < size)
	{
		if (*(int *) stack_iter->content == content)
			return (pos);
		stack_iter = stack_iter->next;
		pos++;
	}
	return (pos);
}
