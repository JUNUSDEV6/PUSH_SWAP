/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:01:10 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/02 14:03:04 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

static void	rotate(t_stack *stack)
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

void	ra(t_stack *a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
