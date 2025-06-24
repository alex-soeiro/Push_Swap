/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:27:06 by avieira-          #+#    #+#             */
/*   Updated: 2025/06/24 21:47:20 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/push_swap.h"
#include "include/libft/include/libft.h"

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

int	main(int argc, char **argv)
{
	int			parsing_ko;
	char		**nums;
	t_dblylst	*stack_a;
	t_dblylst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing_ko = parse(argc, argv, &nums);
	if (parsing_ko)
		return (parsing_ko);

	// Create stack 
	stack_a = createstack_a(nums);
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
	rotate(&stack_a);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_a: ");
	reverse_rotate(&stack_a);
	print_stack(stack_a);

	/* Rotate_Rotate */
	ft_printf("\n\nROTATE_ROTATE\n");
	rotate_rotate(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	/* Swap */
	ft_printf("\n\nSWAP\n");
	swap(&stack_a);
	ft_printf("stack_a:");
	print_stack(stack_a);
	ft_printf("stack_a:");
	swap(&stack_a);
	print_stack(stack_a);

	/* Swap_Swap */
	ft_printf("\n\nSWAP_SWAP\n");
	swap_swap(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	/* Push */
	ft_printf("\n\nPUSH\n");
	push(&stack_a, &stack_b);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);
	push(&stack_b, &stack_a);
	ft_printf("stack_a: ");
	print_stack(stack_a);
	ft_printf("stack_b: ");
	print_stack(stack_b);

	// Free stack a
	ft_dblylst_clear(stack_a);
}
/*
   int	main(int argc, char **argv)
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
   while (i < argc - 1)
   printf("%i, ", middle.array[i++]);
   free(middle.array);
   }*/
