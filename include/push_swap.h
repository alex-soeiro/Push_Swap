/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:15:45 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/12 17:27:30 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_array
{
	int 	*array;
	int		length;
}	t_array;

typedef struct s_node
{
	int		number;
	int		*prev;
	int		*next;
}	t_node;

typedef struct s_stack
{
	int		*head;
	int		*tail;
}	t_stack;

void	merge_sort(t_array middle);
void	merge(t_array left, t_array middle, t_array right);
int		error_message(int error_code);

#endif
