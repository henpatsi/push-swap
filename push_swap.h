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
# include "stack.h"

int		check_input(int len, char **strs);
t_stack	*strs_to_stack(int len, char **strs);

void	push_smallest_sort(t_stack **stack_a, t_stack **stack_b);
void	push_to_place_sort(t_stack **stack_a, t_stack **stack_b);

#endif