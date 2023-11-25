/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:35:46 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 15:35:46 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	record_command(t_stack **stack_a, t_stack **stack_b, char *command, t_list **commands)
{
	char	*content;
	t_list	*entry;

	content = ft_strdup(command);
	if (content == 0)
	{
		free_all(stack_a, stack_b, commands);
		exit (0);
	}
	entry = ft_lstnew(content);
	if (entry == 0)
	{
		free_all(stack_a, stack_b, commands);
		exit (0);
	}
	ft_lstadd_back(commands, entry);
	return (1);
}

void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command, t_list **commands)
{
	record_command(stack_a, stack_b, command, commands);
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
