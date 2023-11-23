/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:05:00 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 16:05:00 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "test.h"

static void	rotate_to_min(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	shortest_dir;

	smallest = get_smallest(stack_a);
	shortest_dir = get_shortest_dir(stack_a, smallest);
	while ((*stack_a)->num != smallest)
	{
		if (shortest_dir == 1)
			exec_command(stack_a, stack_b, "ra");
		else
			exec_command(stack_a, stack_b, "rra");
	}
}

void	push_smallest_sort(t_stack **stack_a, t_stack **stack_b)
{
	print_stacks(*stack_a, *stack_b);
	while (*stack_a != 0)
	{
		// if ((*stack_a)->num > (*stack_a)->next->num)
		// 	exec_command(stack_a, stack_b, "sa");
		rotate_to_min(stack_a, stack_b);
		if (is_descending(stack_a))
			break ;
		exec_command(stack_a, stack_b, "pb");
	}
	while (*stack_b != 0)
	{
		exec_command(stack_a, stack_b, "pa");
	}
	print_stacks(*stack_a, *stack_b);
}