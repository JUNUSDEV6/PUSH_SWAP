/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_silent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:21:47 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:22:40 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_silent(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	else
		stack->bottom = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}

void	sa_silent(t_stack *a)
{
	swap_silent(a);
}

void	sb_silent(t_stack *b)
{
	swap_silent(b);
}

void	ss_silent(t_stack *a, t_stack *b)
{
	swap_silent(a);
	swap_silent(b);
}
