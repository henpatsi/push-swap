/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:23:18 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 10:36:58 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack **stack_x)
{
	t_stack	*tmp;

	if (*stack_x == 0 || (*stack_x)->next == 0)
		return ;
	tmp = *stack_x;
	*stack_x = tmp->next;
	tmp->next = tmp->next->next;
	(*stack_x)->next = tmp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

void	px(t_stack **stack_x, t_stack **stack_y)
{
	t_stack	*tmp;

	if (*stack_y == 0)
		return ;
	tmp = *stack_y;
	*stack_y = tmp->next;
	tmp->next = *stack_x;
	*stack_x = tmp;
}
