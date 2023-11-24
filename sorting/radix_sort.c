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

#include "stack.h"
#include "libft.h"

#include "test.h"

void	int_to_bin(int n, int *bin)
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

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	bin[32];
	int	size;
	int	i;
	int	j;
	
	//print_stacks(*stack_a, *stack_b);
	size = ft_stacksize(*stack_a);
	i = 31;
	while (i >= 0)
	{
		if (*stack_a == 0)
			break ;
		j = 0;
		while (j < size)
		{
			int_to_bin((*stack_a)->num, bin);
			if (bin[i] == 0)
				exec_command(stack_a, stack_b, "pb");
			else
				exec_command(stack_a, stack_b, "ra");
			j++;
		}
		while (*stack_b != 0)
			exec_command(stack_a, stack_b, "pa");
		if (is_descending(stack_a))
			break ;
		i--;
	}
	//print_stacks(*stack_a, *stack_b);
	exec_command(stack_a, stack_b, "print");
}