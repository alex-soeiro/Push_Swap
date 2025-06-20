/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblylst_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:46:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/06/20 21:28:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_doublylist    *ft_dblylst_last(t_doublylist *dblylst)
{
	t_doublylist	*dblylst_iter;

	dblylst_iter = dblylst;
	while (dblylst_iter->next != dblylst)
		dblylst_iter = dblylst_iter->next;
	return (dblylst_iter);
}
