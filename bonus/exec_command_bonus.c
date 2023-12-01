/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:31:07 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 15:16:56 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		sx(stack_a);
	else if (!ft_strcmp(command, "sb\n"))
		sx(stack_b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa\n"))
		px(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb\n"))
		px(stack_b, stack_a);
	else if (!ft_strcmp(command, "ra\n"))
		rx(stack_a);
	else if (!ft_strcmp(command, "rb\n"))
		rx(stack_b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra\n"))
		rrx(stack_a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrx(stack_b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}
