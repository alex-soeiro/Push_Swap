/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblylst_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:18:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/22 20:47:24 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dblylst_clear(t_doublylist *dblylst)
{
	t_doublylist	*tmp;
	t_doublylist	*dblylst_ptr;

	dblylst_ptr = dblylst;
	while (dblylst && dblylst_ptr->next != dblylst)
	{
		tmp = dblylst_ptr->next;
		free(dblylst_ptr->content);
		free(dblylst_ptr);
		dblylst_ptr = tmp;
	}
		tmp = dblylst_ptr->next;
		free(dblylst_ptr->content);
		free(dblylst_ptr);
		dblylst_ptr = tmp;
}
