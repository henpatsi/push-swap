/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:15:14 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 10:54:52 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	int_to_bin(int n, int *bin)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		bin[i] = n & 1;
		n = n >> 1;
		i--;
	}
}

static void	push_zeros(t_stack **stack_a, t_stack **stack_b,
						int bin_index, t_list **commands)
{
	int	bin[32];
	int	size;
	int	i;

	size = ft_stacksize(*stack_a);
	i = 0;
	while (i < size && !is_sorted(stack_a))
	{
		int_to_bin((*stack_a)->num, bin);
		if (bin[bin_index] == 0)
			exec_command(stack_a, stack_b, "pb", commands);
		else
			exec_command(stack_a, stack_b, "ra", commands);
		i++;
	}
}

static void	push_back(t_stack **stack_a, t_stack **stack_b,
						int bin_index, t_list **commands)
{
	int	bin[32];
	int	size;
	int	i;

	size = ft_stacksize(*stack_b);
	i = 0;
	while (i < size)
	{
		if (is_sorted(stack_a))
			exec_command(stack_a, stack_b, "pa", commands);
		else
		{
			int_to_bin((*stack_b)->num, bin);
			if (bin_index == 0 || bin[bin_index - 1] == 1)
				exec_command(stack_a, stack_b, "pa", commands);
			else
				exec_command(stack_a, stack_b, "rb", commands);
		}
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (*stack_a == 0 || is_sorted(stack_a))
			break ;
		push_zeros(stack_a, stack_b, i, commands);
		push_back(stack_a, stack_b, i, commands);
		i--;
	}
}
