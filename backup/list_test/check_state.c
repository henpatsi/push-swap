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

#include "push_swap.h"

// int	is_descending(t_stack **stack_a)
// {
// 	t_stack	*node;

// 	if (*stack_a == 0)
// 		return (0);
// 	node = *stack_a;
// 	while (node->next != 0)
// 	{
// 		if (node->num > node->next->num)
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }

// int	is_ascending(t_stack **stack_b)
// {
// 	t_stack	*node;

// 	if (*stack_b == 0)
// 		return (0);
// 	node = *stack_b;
// 	while (node->next != 0)
// 	{
// 		if (node->num < node->next->num)
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }

// int	get_smallest(t_stack **stack_x)
// {
// 	t_stack	*node;
// 	int		smallest;

// 	if (*stack_x == 0)
// 		return (0);
// 	node = *stack_x;
// 	smallest = node->num;
// 	while (node != 0)
// 	{
// 		if (node->num < smallest)
// 			smallest = node->num;
// 		node = node->next;
// 	}
// 	return (smallest);
// }

// int	get_largest(t_stack **stack_x)
// {
// 	t_stack	*node;
// 	int		largest;

// 	if (*stack_x == 0)
// 		return (0);
// 	node = *stack_x;
// 	largest = node->num;
// 	while (node != 0)
// 	{
// 		if (node->num > largest)
// 			largest = node->num;
// 		node = node->next;
// 	}
// 	return (largest);
// }