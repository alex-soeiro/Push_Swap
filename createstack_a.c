/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createstack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:56:20 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/06/22 04:04:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft/include/libft.h"
#include "include/push_swap.h"

t_doublylist	*createstack_a(char **nums)
{
	long			*content;
	char			**nums_ptr;
	t_doublylist	*dblylst;
	t_doublylist	*new_node;


	nums_ptr = nums;
	dblylst = NULL;
	while (*nums)
	{
		content = malloc(sizeof(long));
		if (!content)
		   return (NULL);	
		*content = ft_atol(*(nums++));
		new_node = ft_dblylst_new(content);
		if (dblylst == NULL)
		{
			new_node->next = new_node;
			new_node->prev = new_node;
			dblylst = new_node;
		}
		else
			ft_dblylst_addback(dblylst, new_node);
	}
	return (dblylst);
	//return (ft_free_matrix(nums_ptr), dblylst);
}
