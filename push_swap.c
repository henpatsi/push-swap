/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 15:09:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include "test.h"

// int	is_sorted(t_stack	**stack_a)
// {
// 	t_stack	*node;

// 	node = *stack_a;
// 	while (node->next != 0)
// 	{
// 		if (node->num > node->next->num)
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }

void	sort_stack(t_stack	**stack_a, t_stack	**stack_b)
{
	

	// ft_printf("is sorted: %i\n", is_sorted(stack_a));
	// print_stacks(*stack_a, *stack_b);
	// command(stack_a, stack_b, "sa");
	// ft_printf("is sorted: %i\n", is_sorted(stack_a));
	// print_stacks(*stack_a, *stack_b);
	// command(stack_a, stack_b, "pb");
	// command(stack_a, stack_b, "pb");
	// command(stack_a, stack_b, "pb");
	// ft_printf("is sorted: %i\n", is_sorted(stack_a));
	// print_stacks(*stack_a, *stack_b);
	// command(stack_a, stack_b, "sa");
	// ft_printf("is sorted: %i\n", is_sorted(stack_a));
	// print_stacks(*stack_a, *stack_b);
	// command(stack_a, stack_b, "pa");
	// command(stack_a, stack_b, "pa");
	// command(stack_a, stack_b, "pa");
	// ft_printf("is sorted: %i\n", is_sorted(stack_a));
	// print_stacks(*stack_a, *stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || !check_input(argc - 1, &argv[1]))
	{
		ft_printf("Error");
		return (0);
	}
	stack_a = strs_to_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	sort_stack(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
