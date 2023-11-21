/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:02:18 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/21 15:02:37 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_input(int len, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while(strs[i][j] != 0)
		{
			if (!ft_isdigit(strs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	*atoi_list(int len, char **strs)
{
	int	*ints;
	int	i;

	ints = malloc(len * sizeof(int));
	if (ints == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ints[i] = ft_atoi(strs[i]);
		i++;
	}
	return (ints);
}