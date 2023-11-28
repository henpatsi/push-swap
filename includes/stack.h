/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:27:44 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/23 15:27:44 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "stack.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int n);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
int		is_sorted(t_stack **stack_a);
int		get_smallest(t_stack **stack_x);
int		get_largest(t_stack **stack_x);
int		get_shortest_dir(t_stack **stack_x, int i);
int		is_sorted_looping(t_stack **stack_a);

#endif