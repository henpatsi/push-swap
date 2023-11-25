/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:15:14 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 21:15:14 by hpatsi           ###   ########.fr       */
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

static void	push_zeros(t_stack **stack_a, t_stack **stack_b, int bin_index, t_list **commands)
{
	int	bin[32];
	int	size;
	int	i;

	size = ft_stacksize(*stack_a);
	i = 0;
	while (i < size)
	{
		int_to_bin((*stack_a)->num, bin);
		if (bin[bin_index] == 0)
			exec_command(stack_a, stack_b, "pb", commands);
		else
			exec_command(stack_a, stack_b, "ra", commands);
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands)
{
	int		i;
	
	i = 31;
	while (i >= 0)
	{
		if (*stack_a == 0)
			break ;
		push_zeros(stack_a, stack_b, i, commands);
		while (*stack_b != 0)
			exec_command(stack_a, stack_b, "pa", commands);
		if (is_descending(stack_a))
			break ;
		i--;
	}
}