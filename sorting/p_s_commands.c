/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:23:18 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/25 12:23:18 by hpatsi           ###   ########.fr       */
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

void	px(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == 0)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	ft_stackadd_front(stack_a, tmp);
}
