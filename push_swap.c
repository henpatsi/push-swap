/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 15:26:41 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_list *commands)
{
	t_list	*node;

	node = commands;
	while (node != 0)
	{
		ft_printf("%s\n", node->content);
		node = node->next;
	}
}

void	free_all(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	ft_lstclear(commands, &free);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*commands;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = make_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	commands = 0;
	if (ft_stacksize(stack_a) <= 3)
		tiny_sort(&stack_a, &stack_b, &commands);
	else if (ft_stacksize(stack_a) <= 50)
		push_smallest_sort(&stack_a, &stack_b, &commands);
	else
		radix_sort(&stack_a, &stack_b, &commands);
	//optimize_commands(commands);
	print_commands(commands);
	free_all(&stack_a, &stack_b, &commands);
	return (0);
}
