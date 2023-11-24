/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:17 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/24 14:23:17 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#include "test.h"

void	tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
	print_stacks(*stack_a, *stack_b);
	if (is_descending(stack_a))
		return ;
	if ((*stack_a)->num == get_largest(stack_a))
		exec_command(stack_a, stack_b, "ra");
	else if (ft_stacklast(*stack_a)->num != get_largest(stack_a))
		exec_command(stack_a, stack_b, "rra");
	if (!is_descending(stack_a))
		exec_command(stack_a, stack_b, "sa");
	print_stacks(*stack_a, *stack_b);
}