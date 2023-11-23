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

int	check_input(int len, char **strs);
int	*strs_to_stack(int len, char **strs);
// t_stack	*ft_stacklast(t_stack *stack);
// t_stack	*ft_stacknew(int n);
// void	ft_stackadd_front(t_stack **stack, t_stack *new);
// void	ft_stackadd_back(t_stack **stack, t_stack *new);
// void	ft_stackclear(t_stack **stack);

// int		is_descending(t_stack **stack_a);
// int		is_ascending(t_stack **stack_b);
// int		get_smallest(t_stack **stack_x);
// int		get_largest(t_stack **stack_x);

int	command(int *stack_a, int *stack_b, char *command);

#endif