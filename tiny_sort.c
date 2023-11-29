/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:17 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/28 11:29:16 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->num == get_largest(stack_a))
		exec_command(stack_a, stack_b, "ra", commands);
	else if (ft_stacklast(*stack_a)->num != get_largest(stack_a))
		exec_command(stack_a, stack_b, "rra", commands);
	if (!is_sorted(stack_a))
		exec_command(stack_a, stack_b, "sa", commands);
}
