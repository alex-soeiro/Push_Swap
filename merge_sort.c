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

#include "include/push_swap.h"

void	merge_sort(t_array middle)
{
	t_array	left;
	t_array	right;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (middle.length > 1)
	{
		left.length = middle.length / 2;
		right.length = middle.length / 2 + middle.length % 2;
		left.array = malloc(left.length * sizeof(int));
		right.array = malloc(right.length * sizeof(int));
		if (!left.array || !right.array)
			return ;
		while (i < left.length)
			left.array[j++] = middle.array[i++];
		j = 0;
		while (i < middle.length)
			right.array[j++] = middle.array[i++];
		merge_sort(left);
		merge_sort(right);
		merge(left, middle, right);
	}
}

void	merge(t_array left, t_array middle, t_array right)
{
	int		l;
	int		m;
	int		r;

	l = 0;
	m = 0;
	r = 0;
	while (m < middle.length)
	{
		if (l < left.length && left.array[l] <= right.array[r])
			middle.array[m++] = left.array[l++];
		else if (r < right.length && right.array[r] <= left.array[l])
			middle.array[m++] = right.array[r++];
		else if (l < left.length && r >= right.length)
			middle.array[m++] = left.array[l++];
		else if (r < right.length && l >= left.length)
			middle.array[m++] = right.array[r++];
	}
}
