/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:30 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 10:32:30 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_commands(char **commands)
{
	int i;

	i = 0;
	while (commands[i] != 0)
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}

void	free_all(t_stack **stack_a, t_stack **stack_b, char **commands)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	free_commands(commands);
}

static char	**read_commands(void)
{
	char	**commands;
	char	*read_str;
	int	i;
	int	read_size;

	commands = malloc(100 * sizeof(char *));
	if (commands == 0)
		return (0);
	i = 0;
	read_size = 0;
	while (read_size != 1)
	{
		read_str = ft_calloc(5, sizeof(char));
		if (read_str == 0)
		{
			free_commands(commands);
			return (0);
		}
		read_size = read(0, read_str, 4);
		commands[i] = read_str;
		i++;
	}
	commands[i] = 0;
	return (commands);
}



void	print_stack(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node != 0)
	{
		ft_printf("%i\n", node->num);
		node = node->next;
	}
}



int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**commands;

	if (argc < 2)
		return (0);
	stack_a = make_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	commands = read_commands();

	// TODO MOVE COMMAND CLEANING TO READ INSTEAD OF EXEC ??!?!?

	exec_command_list(&stack_a, &stack_b, commands);
	if (is_sorted(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stack_a, &stack_b, commands);
	return (0);
}