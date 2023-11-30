/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:25:51 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 09:36:46 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\na:\n\n");
	print_stack(stack_a);
	ft_printf("\nb:\n\n");
	print_stack(stack_b);
	ft_printf("\n--------------\n");
}

void	print_bin(int *bin)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		ft_printf("%i", bin[i]);
		i++;
	}
	ft_printf("\n");
}