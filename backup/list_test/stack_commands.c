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

#include "push_swap.h"

static void	px(int *stack_a, int *stack_b)
{
	
}

int	command(int *stack_a, int *stack_b, char *command)
{
	static int	moves;

	moves += 1;
	ft_printf("command #%i: %s\n", moves, command);
	// if (!ft_strcmp(command, "sa"))
	// 	sx(stack_a);
	// else if (!ft_strcmp(command, "sb"))
	// 	sx(stack_b);
	// else if (!ft_strcmp(command, "ss"))
	// 	ss(stack_a, stack_b);
	if (!ft_strcmp(command, "pa"))
		px(stack_a, stack_b);
	else if (!ft_strcmp(command, "pb"))
		px(stack_b, stack_a);
	// else if (!ft_strcmp(command, "ra"))
	// 	rx(stack_a);
	// else if (!ft_strcmp(command, "rb"))
	// 	rx(stack_b);
	// else if (!ft_strcmp(command, "rr"))
	// 	rr(stack_a, stack_b);
	// else if (!ft_strcmp(command, "rra"))
	// 	rrx(stack_a);
	// else if (!ft_strcmp(command, "rrb"))
	// 	rrx(stack_b);
	// else if (!ft_strcmp(command, "rrr"))
	// 	rrr(stack_a, stack_b);
	return (moves);
}
