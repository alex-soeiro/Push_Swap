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

void	merge_sort(s_array middle)
{	
	s_array left;
	t_array right;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (middle.length > 1)
	{
		left.length = middle.length / 2;
		right.length = middle.length / 2 + middle.length % 2;
		left.string = malloc(left.length * sizeof(int));
		right.string = malloc(right.length * sizeof(int));
		if (!left.string || !right.string)
			return (NULL);
		while (i < left.length)
			left.string[i] = middle.string[i++];
		while (i < right.length)
			left.string[j++] = middle.string[i++];
		merge_sort(left);
		merge_sort(right);
		merge(left, middle, right);
	}
}

int		main(s_array left, s_array middle, s_array right)
{
	int		l_len;
	int		m_len;
	int		r_len;

	l = 0;
	m = 0;
	r = 0;
	while (m_len < middle.length)
	{
		if (l < left.length && left.string[l] < right.string[r])
			middle.string[m++] = left.string[l++];
		else if (r < right.length && right.string[r] < left.string[l])
			middle.string[m++] = right.string[r++];
		else if (l < left.length && r >= right.length)
			middle.string[m++] = left.string[l++];
		else if (r < right.length && l > left.length)
			middle.string[m++] = right.string[r++];
	}
}
