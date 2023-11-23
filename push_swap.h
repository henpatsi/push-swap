/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:48:27 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 13:50:50 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

int		check_input(int len, char **strs);
t_stack	*strs_to_stack(int len, char **strs);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int n);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

int		is_descending(t_stack **stack_a);
int		is_ascending(t_stack **stack_b);
int		get_smallest(t_stack **stack_x);
int		get_largest(t_stack **stack_x);

void	sx(t_stack **stack_x);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	px(t_stack **stack_a, t_stack **stack_b);
void	rx(t_stack **stack_x);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrx(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif