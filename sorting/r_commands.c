/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:23:41 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/28 12:20:39 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack **stack_x)
{
	t_stack	*tmp;

	if (*stack_x == 0 || (*stack_x)->next == 0)
		return ;
	tmp = *stack_x;
	ft_stackadd_back(stack_x, *stack_x);
	*stack_x = tmp->next;
	tmp->next = 0;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

void	rrx(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != 0)
		tmp = tmp->next;
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = 0;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
