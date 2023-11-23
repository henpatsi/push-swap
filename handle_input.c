/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:02:18 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 09:55:22 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	check_input(int len, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			if (!ft_isdigit(strs[i][j]))
			{
				if (j != 0 || strs[i][j] != '-')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

t_stack	*strs_to_stack(int len, char **strs)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = 0;
	i = 0;
	while (i < len)
	{
		node = ft_stacknew(ft_atoi(strs[i]));
		if (node == 0)
		{
			ft_stackclear(&stack);
			return (0);
		}
		ft_stackadd_back(&stack, node);
		i++;
	}
	return (stack);
}
