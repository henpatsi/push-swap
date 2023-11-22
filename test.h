/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:05:05 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/22 13:42:56 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "push_swap.h"
# include "libft.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	command(t_stack **stack_a, t_stack **stack_b, char *command);

#endif