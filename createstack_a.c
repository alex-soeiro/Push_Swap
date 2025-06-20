/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:56:20 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/06/20 16:58:50 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

t_doublylist	*createstack_a(char **nums)
{
	t_doublylist	*dblylst;
	t_doublylist	*new_node;

	dblylst = NULL;
	while (*nums)
	{
		new_node = ft_dblylst_new(*(nums++));
		if (dblylst == NULL)
		{
			dblylst = new_node;
			dblylst->next = new_node;
			dblylst->prev = new_node;
		}
		else
			ft_dblylst_addback(dblylst, new_node);
	}
	return (dblylst);
}
