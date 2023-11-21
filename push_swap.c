/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/21 15:45:36 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stack(int len, int *ints)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%i\n", ints[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*ints;
	
	if (argc < 2 || !check_input(argc - 1, &argv[1]))
	{
		ft_printf("Error");
		return (0);
	}
	ints = atoi_list(argc - 1, &argv[1]);
	print_stack(argc - 1, ints);
}
