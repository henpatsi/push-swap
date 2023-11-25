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

static int	*error(void)
{
	ft_printf("Error\n");
	return (0);
}

static int	atoi_check(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i]))
		{
			if (i != 0 || str[i] != '-')
				return (0);
		}
		i++;
	}
	num = ft_atoi(str);
	if (num != ft_atol(str))
		return (0);
	return (num);
}

static int	*strs_to_ints(int len, char **strs)
{
	int	i;
	int	j;
	int	*ints;

	ints = malloc(len * sizeof(int));
	if (ints == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ints[i] = atoi_check(strs[i]);
		if (ints[i] == 0 && ft_strcmp(strs[i], "0") != 0)
			return (error());
		j = 0;
		while (j < i)
		{
			if (ints[i] == ints[j])
				return error();
			j++;
		}
		i++;
	}
	return (ints);
}

static int	*strs_to_ranks(int len, char **strs)
{
	int	i;
	int	j;
	int	*ints;
	int	*ranks;

	ints = strs_to_ints(len, strs);
	if (ints == 0)
		return (0);
	ranks = malloc(len * sizeof(int));
	if (ranks == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		j = 0;
		ranks[i] = 1;
		while (j < i)
		{
			if (ints[j] > ints[i])
				ranks[j]++;
			else
				ranks[i]++;
			j++;
		}
		i++;
	}
	free(ints);
	return (ranks);
}

t_stack	*make_stack(int len, char **strs)
{
	t_stack	*stack;
	t_stack	*node;
	int		*ranks;
	int		i;

	ranks = strs_to_ranks(len, strs);
	if (ranks == 0)
		return (0);
	stack = 0;
	i = 0;
	while (i < len)
	{
		node = ft_stacknew(ranks[i]);
		if (node == 0)
		{
			free(ranks);
			ft_stackclear(&stack);
			return (0);
		}
		ft_stackadd_back(&stack, node);
		i++;
	}
	free(ranks);
	return (stack);
}
