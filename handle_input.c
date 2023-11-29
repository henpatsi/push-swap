/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:02:18 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 12:43:03 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	add_int(int *ints, char **strs, int i)
{
	ints[i] = atoi_check(strs[i]);
	if (ints[i] == 0 && ft_strcmp(strs[i], "0") != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

static int	add_rank(int *ranks, int *ints, int i)
{
	int	j;

	j = 0;
	ranks[i] = 1;
	while (j < i)
	{
		if (ints[i] == ints[j])
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (ints[j] > ints[i])
			ranks[j]++;
		else
			ranks[i]++;
		j++;
	}
	return (1);
}

static int	*strs_to_ranks(int len, char **strs)
{
	int	i;
	int	*ints;
	int	*ranks;

	ints = malloc(len * sizeof(int));
	if (ints == 0)
		return (0);
	ranks = malloc(len * sizeof(int));
	if (ranks == 0)
	{
		free(ints);
		return (0);
	}
	i = -1;
	while (++i < len)
	{
		if (add_int(ints, strs, i) == 0 || add_rank(ranks, ints, i) == 0)
		{
			free(ints);
			free(ranks);
			return (0);
		}
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
