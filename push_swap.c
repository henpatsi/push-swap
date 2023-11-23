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
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || !check_input(argc - 1, &argv[1]))
	{
		ft_printf("Error");
		return (0);
	}
	stack_a = strs_to_stack(argc - 1, &argv[1]);
	if (stack_a == 0)
		return (0);
	stack_b = 0;
	push_smallest_sort(&stack_a, &stack_b);
	//push_to_place_sort(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
