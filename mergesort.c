/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesusoncrack <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:43:18 by jesusoncrack      #+#    #+#             */
/*   Updated: 2025/03/24 18:31:31 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	merge(char **left, char **middle, char **right,int ll, int ml, int rl)
{
	int	l;
	int	m;
	int	r;

	l = 0;
	m = 0;
	r = 0;
	while (m < ml)
	{
		if (l < ll && r < rl && (ft_strcmp(left[l], right[r]) <= 0))
		{
			middle[m] = left[l];
			l++;
		}
		else if (r < rl && l < ll && (ft_strcmp(right[r], left[l]) < 0))
		{
			middle[m] = right[r];
			r++;
		}
		else if (l < ll && r >= rl)
		{
			middle[m] = left[l];
			l++;
		}
		else if (r < rl && l >= ll)
		{
			middle[m] = right[r];
			r++;
		}
		m++;
	}
}

void	mergesort(char **middle, int size)
{
	int	i;
	int	j;
	int	ll;
	int	rl;
	char	*left[(size / 2) + (size % 2)];
	char	*right[size / 2];

	i = 0;
	j = 0;
	if (size > 1)
	{
		for (; i < (size / 2) + (size % 2); i++)
			left[i] = middle[i];
		ll = i;
		for (; i < size; i++, j++)
			right[j] = middle[i];
		rl = j;
		mergesort(left, ll);
		mergesort(right, rl);
		merge(left, middle, right, ll, size, rl);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;

	if (argc > 1)
	{
		mergesort(&argv[1], argc - 1);
		while (i < argc)
		{
			printf("%s\n", argv[i]);
			i++;
		}
	}
}


















