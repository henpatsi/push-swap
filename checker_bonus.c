/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:30 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/30 10:56:36 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != 0)
	{
		if (exec_command(stack_a, stack_b, line) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

static t_stack	*stack_from_str(char *str)
{
	t_stack	*stack_a;
	char	**strs;
	int		len;
	int		i;

	strs = ft_split(str, ' ');
	if (strs == 0)
		return (0);
	len = 0;
	while (strs[len] != 0)
		len++;
	stack_a = make_stack(len, strs);
	i = 0;
	while(i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = stack_from_str(argv[1]);
	else
		stack_a = make_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	if (read_commands(&stack_a, &stack_b) != 0)
	{
		if (is_sorted(&stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
