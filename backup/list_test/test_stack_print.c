/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:25:51 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 14:28:02 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_stack(int *stack, int len)
{
	int i;

	if (*stack == 0)
	{
		ft_printf("(empty)\n");
		return ;
	}
	i = 0;
	while (i < len)
	{
		ft_printf("%i\n", stack[i]);
		i++;
	}
}

void	print_stacks(int *stack_a, int *stack_b, int len)
{
	ft_printf("\na:\n\n");
	print_stack(stack_a, len);
	ft_printf("\nb:\n\n");
	print_stack(stack_b, len);
	ft_printf("\n--------------\n");
}
