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

#include "push_swap.h"

void	free_all(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	ft_lstclear(commands, &free);
}

char	**read_commands(void)
{
	char	**commands;
	char	*read_str;
	int	i;
	int	read_size;

	commands = malloc(100 * sizeof(char *));
	i = 0;
	read_size = 0;
	while (read_size != 1)
	{
		read_str = ft_calloc(4, sizeof(char));
		read_size = read(0, read_str, 4);
		commands[i] = read_str;
		i++;
	}
	commands[i] = 0;
	return (commands);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b;
	char	**commands;

	if (argc < 2)
		return (0);
	stack_a = make_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	// stack_b = 0;
	commands = read_commands();
	while (*commands != 0)
	{
		ft_printf("%s", *commands);
		commands++;
	}
}