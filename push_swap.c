/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/30 10:50:57 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	ft_lstclear(commands, &free);
}

static void	optimize_commands(t_list **node)
{
	t_list	*tmp;
	char	*c1;
	char	*c2;

	tmp = *node;
	if (tmp->next == 0)
		return ;
	c1 = tmp->content;
	c2 = tmp->next->content;
	if ((!ft_strcmp(c1, "pa") && !ft_strcmp(c2, "pb"))
		|| (!ft_strcmp(c1, "pb") && !ft_strcmp(c2, "pa")))
	{
		*node = tmp->next->next;
	}
	else if ((!ft_strcmp(c1, "ra") && !ft_strcmp(c2, "rb"))
		|| (!ft_strcmp(c1, "rb") && !ft_strcmp(c2, "ra")))
	{
		ft_printf("rr\n");
		*node = tmp->next->next;
	}
}

static void	print_commands(t_list *commands)
{
	t_list	*node;

	node = commands;
	while (node != 0)
	{
		optimize_commands(&node);
		ft_printf("%s\n", node->content);
		node = node->next;
	}
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
	t_list	*commands;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = stack_from_str(argv[1]);
	else
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
	print_commands(commands);
	free_all(&stack_a, &stack_b, &commands);
	return (0);
}
