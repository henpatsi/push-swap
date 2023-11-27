/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:31:07 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/27 13:31:07 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
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

void	exec_command_list(t_stack **stack_a, t_stack **stack_b, char **commands)
{
	int		i;
	char	*command;

	i = 0;
	while (commands[i] != 0)
	{
		command = ft_strtrim(commands[i], "\n");
		if (command == 0)
			return ;
		ft_printf("exec: %s\n", command);
		exec_command(stack_a, stack_b, command);
		free(command);
		i++;
	}
	stack_a += 1;
	stack_b += 1;
}