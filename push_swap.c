/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/25 18:56:32 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/push_swap.h"
#include "include/libft/include/libft.h"

t_array	normalize(int argc, char **argv)
{
	int		i;
	int		j;
	t_array	middle;

	i = 1;
	j = 0;
	middle.length = argc - 1;
	middle.array = malloc((argc - 1) * sizeof(int));
	while (i < argc)
		middle.array[j++] = ft_atoi(argv[i++]);
	i = 0;
	merge_sort(middle);
	free(middle.array);
	return (middle);
}

void	print_stack(t_dblylst *stack)
{
	t_dblylst	*stack_iter;

	stack_iter = stack;
	if (!stack)
		return ;
	while (stack_iter->next != stack)
	{
		ft_printf("%i, ", *(int *) stack_iter->content);
		stack_iter = stack_iter->next;
	}
	ft_printf("%i\n", *(int *) stack_iter->content);
}

void	is_ordered(t_array ordered, t_dblylst stack_a)
{
	while 
}


int	main(int argc, char **argv)
{
	int			parsing_ko;
	char		**nums;
	t_array		ordered;
	t_dblylst	*stack_a;
	t_dblylst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing_ko = parse(argc, argv, &nums);
	if (parsing_ko)
		return (parsing_ko);

	// Normalize
	ordered = normalize(argc, argv);

	// Create stack 
	stack_a = createstack_a(nums);

	/*if (is_ordered(stack_a))
	{
		print_stack(stack_a);
		return (ft_dblylst_clear(stack_a), 0);
	}*/
	ft_printf("stack_a: ");
	print_stack(stack_a);

	// DEBUG: Print stack a
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	// DEBUG MOVEMENTS

	/* Rotate */
	ft_printf("\n\nROTATE\n");
	ra(&stack_a);
	ft_printf("stack_a: ");
	print_stack(stack_a);

	/* Rotate_Rotate */
	ft_printf("\n\nROTATE_ROTATE\n");
	rr(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	/* Reverse_Rotate */
	ft_printf("\n\nREVERSE_ROTATE\n");
	ft_printf("stack_a: ");
	rra(&stack_a);
	print_stack(stack_a);

	/* Swap */
	ft_printf("\n\nSWAP\n");
	sa(&stack_a);
	ft_printf("stack_a:");
	print_stack(stack_a);
	ft_printf("stack_a:");
	sa(&stack_a);
	print_stack(stack_a);

	/* Swap_Swap */
	ft_printf("\n\nSWAP_SWAP\n");
	ss(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	/* Push */
	ft_printf("\n\nPUSH\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);
	pb(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	// Free stack a
	ft_dblylst_clear(stack_a);
}
