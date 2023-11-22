/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:28:38 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 15:19:48 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	sx(t_stack **stack_x)
{
	t_stack	*tmp;

	if (*stack_x == 0 || (*stack_x)->next == 0)
		return ;
	tmp = *stack_x;
	*stack_x = tmp->next;
	tmp->next = tmp->next->next;
	(*stack_x)->next = tmp;
}

static void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

static void	px(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b == 0)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	ft_stackadd_front(stack_a, tmp);
}

static void	rx(t_stack **stack_x)
{
	t_stack	*tmp;

	if (*stack_x == 0 || (*stack_x)->next == 0)
		return ;
	tmp = *stack_x;
	ft_stackadd_back(stack_x, *stack_x);
	*stack_x = tmp->next;
	tmp->next = 0;
}

static void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

static void	rrx(t_stack **stack_a)
{
	t_stack	*tmp;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != 0)
		tmp = tmp->next;
	ft_stackadd_front(stack_a, tmp->next);
	*stack_a = tmp->next;
	tmp->next = 0;
}

static void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}

void	command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	ft_printf("command: %s\n", command);
	if (!ft_strcmp(command, "sa"))
		sx(stack_a);
	else if (!ft_strcmp(command, "sb"))
		sx(stack_b);
	else if (!ft_strcmp(command, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa"))
		px(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb"))
		px(stack_b, stack_a);
	else if (!ft_strcmp(command, "ra"))
		rx(stack_a);
	else if (!ft_strcmp(command, "rb"))
		rx(stack_b);
	else if (!ft_strcmp(command, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra"))
		rrx(stack_a);
	else if (!ft_strcmp(command, "rrb"))
		rrx(stack_b);
	else if (!ft_strcmp(command, "rrr"))
		rrr(stack_a, stack_b);
}
