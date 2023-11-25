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

#include "push_swap.h"

static void	rotate_to_min(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	int	smallest;
	int	shortest_dir;

	smallest = get_smallest(stack_a);
	shortest_dir = get_shortest_dir(stack_a, smallest);
	while ((*stack_a)->num != smallest)
	{
		if (shortest_dir == 1)
			exec_command(stack_a, stack_b, "ra", commands);
		else
			exec_command(stack_a, stack_b, "rra", commands);
	}
}

void	push_smallest_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	while (*stack_a != 0)
	{
		rotate_to_min(stack_a, stack_b, commands);
		if (is_descending(stack_a))
			break ;
		exec_command(stack_a, stack_b, "pb", commands);
	}
	while (*stack_b != 0)
	{
		exec_command(stack_a, stack_b, "pa", commands);
	}
}