/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:48:27 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/29 09:38:52 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "libft.h"

t_stack	*make_stack(int len, char **strs);
void	tiny_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands);
void	push_smallest_sort(t_stack **stack_a, t_stack **stack_b,
			t_list **commands);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_list **commands);
void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command,
			t_list **commands);
void	sx(t_stack **stack_x);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	px(t_stack **stack_a, t_stack **stack_b);
void	rx(t_stack **stack_x);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrx(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	free_all(t_stack **stack_a, t_stack **stack_b, t_list **commands);

#endif