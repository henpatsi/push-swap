/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:39:12 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/28 12:23:56 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*node;

	if (*stack_a == 0)
		return (0);
	node = *stack_a;
	while (node->next != 0)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}
