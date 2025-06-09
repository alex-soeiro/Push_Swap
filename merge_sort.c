/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:35:26 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/09 22:14:12 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_array middle)
{	
	left_swap left;
	push_swap right;
	
	left.size = middle.size / 2;
	right.size = middle.size / 2 + middle.size % 2;
	left.array = malloc(left.size * sizeof(int));
	right.array = malloc(right.size * sizeof(int));
}
