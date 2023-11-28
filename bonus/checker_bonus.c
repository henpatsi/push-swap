/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:30 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/28 12:44:11 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	read_str[5];
	char	command[4];
	int		i;
	int		read_size;

	read_size = 0;
	while (read_size != 1)
	{
		ft_bzero(read_str, 5);
		read_size = read(0, read_str, 4);
		i = 0;
		while (read_str[i] != 0 && read_str[i] != '\n')
		{
			command[i] = read_str[i];
			i++;
		} // add check that \n reached and correct command, else error
		command[i] = 0;
		exec_command(stack_a, stack_b, command);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = make_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	read_commands(&stack_a, &stack_b);
	if (is_sorted(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
