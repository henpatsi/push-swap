/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:34 by hpatsi            #+#    #+#             */
/*   Updated: 2023/11/28 12:43:35 by hpatsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

t_stack	*make_stack(int len, char **strs);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int n);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command);
void	sx(t_stack **stack_x);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	px(t_stack **stack_a, t_stack **stack_b);
void	rx(t_stack **stack_x);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrx(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack_a);

#endif