/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:16:35 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:18:12 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate_silent(t_stack *stack)
{
	t_node	*old_bottom;

	if (!stack || stack->size < 2)
		return ;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
}

void	rra_silent(t_stack *stack_a)
{
	reverse_rotate_silent(stack_a);
}

void	rrb_silent(t_stack *stack_b)
{
	reverse_rotate_silent(stack_b);
}

void	rrr_silent(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_silent(stack_a);
	reverse_rotate_silent(stack_b);
}
