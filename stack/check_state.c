/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:22:54 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 11:22:54 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "push_swap.h"

int	is_descending(t_stack **stack_a)
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

int	get_smallest(t_stack **stack_x)
{
	t_stack	*node;
	int		smallest;

	if (*stack_x == 0)
		return (0);
	node = *stack_x;
	smallest = node->num;
	while (node != 0)
	{
		if (node->num < smallest)
			smallest = node->num;
		node = node->next;
	}
	return (smallest);
}

int	get_largest(t_stack **stack_x)
{
	t_stack	*node;
	int		largest;

	if (*stack_x == 0)
		return (0);
	node = *stack_x;
	largest = node->num;
	while (node != 0)
	{
		if (node->num > largest)
			largest = node->num;
		node = node->next;
	}
	return (largest);
}

int	get_shortest_dir(t_stack **stack_x, int i)
{
	t_stack	*node;
	int		moves_to_i;
	int		moves;

	if (*stack_x == 0)
		return (0);
	node = *stack_x;
	moves_to_i = 0;
	moves = 0;
	while (node != 0)
	{
		if (node->num == i)
			moves_to_i = moves;
		moves++;
		node = node->next;
	}
	if (moves_to_i < moves - moves_to_i + 1)
		return (1);
	return (2);
}
