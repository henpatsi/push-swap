/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:02:19 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 12:13:46 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_stack	*ft_stacknew(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == 0)
		return (0);
	node->next = 0;
	node->num = n;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*node;

	if (stack == 0)
		return (stack);
	node = stack;
	while (node->next != 0)
		node = node->next;
	return (node);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (*stack == 0)
		*stack = new;
	else
		ft_stacklast(*stack)->next = new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (stack == 0)
		return ;
	node = *stack;
	while (node != 0)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*stack = 0;
}
