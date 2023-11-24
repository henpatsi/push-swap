/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_place_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:10:15 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 16:10:15 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "test.h"

static int	get_smallest_dif(int n, t_stack **stack_x)
{
	t_stack	*node;
	int		dif;
	int		smallest_dif;

	if (*stack_x == 0)
		return (0);
	node = *stack_x;
	smallest_dif = -1;
	while (node != 0)
	{
		dif = n - node->num;
		if (dif > 0 && (smallest_dif < 0 || dif < smallest_dif))
			smallest_dif = dif;
		node = node->next;
	}
	return (smallest_dif);
}

static void	rotate_to_place(t_stack **stack_a, t_stack **stack_b)
{
	int	closest_small;
	int	smallest_dif;
	int	smallest_dir;

	if (*stack_b == 0)
		return ;
	smallest_dif = get_smallest_dif((*stack_a)->num, stack_b);
	if (smallest_dif < 0)
		closest_small = get_largest(stack_b);
	else
		closest_small = (*stack_a)->num - smallest_dif;
	smallest_dir = get_shortest_dir(stack_b, closest_small);
	while ((*stack_b)->num != closest_small)
	{
		if (smallest_dir == 1)
			exec_command(stack_a, stack_b, "rb");
		else
			exec_command(stack_a, stack_b, "rrb");
	}
}

void	push_to_place_sort(t_stack **stack_a, t_stack **stack_b)
{
	//print_stacks(*stack_a, *stack_b);
	while (*stack_a != 0)
	{
		rotate_to_place(stack_a, stack_b);
		exec_command(stack_a, stack_b, "pb");
	}
	while (*stack_b != 0)
		exec_command(stack_a, stack_b, "pa");
	while (!is_descending(stack_a))
		exec_command(stack_a, stack_b, "ra");
	//print_stacks(*stack_a, *stack_b);
	exec_command(stack_a, stack_b, "print");
}