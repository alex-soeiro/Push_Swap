/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:02:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/24 17:03:13 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "include/libft/include/libft.h"

int	error_message(int error_code)
{
	if (error_code == 1)
	{
		ft_printf("error_code 1");
		return (1);
	}
	if (error_code == 2)
	{
		ft_printf("error_code 2");
		return (2);
	}
	if (error_code == 3)
	{
		ft_printf("error_code 3");
		return (3);
	}
	if (error_code == 4)
	{
		ft_printf("error_code 4");
	}
	return (0);
}
