/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_silent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:19:32 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:20:40 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_silent(t_stack *stack)
{
	t_node	*old_top;

	if (!stack || stack->size < 2)
		return ;
	old_top = stack->top;
	stack->top = old_top->next;
	stack->top->prev = NULL;
	old_top->next = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
}

void	ra_silent(t_stack *stack_a)
{
	rotate_silent(stack_a);
}

void	rb_silent(t_stack *stack_b)
{
	rotate_silent(stack_b);
}

void	rr_silent(t_stack *stack_a, t_stack *stack_b)
{
	rotate_silent(stack_a);
	rotate_silent(stack_b);
}
