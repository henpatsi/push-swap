/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 15:26:41 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include "test.h"

void	rotate_tomin(t_stack **stack_a)
{
	int	smallest;

	smallest = get_smallest(stack_a);
	while ((*stack_a)->num != smallest)
		rx(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	print_stacks(*stack_a, *stack_b);

	while (*stack_a != 0)
	{
		rotate_tomin(stack_a);
		px(stack_b, stack_a);
	}
	print_stacks(*stack_a, *stack_b);
	while (*stack_b != 0)
	{
		px(stack_a, stack_b);
	}
	print_stacks(*stack_a, *stack_b);
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
