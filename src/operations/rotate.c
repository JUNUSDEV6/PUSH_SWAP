/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/23 12:30:23 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

static void rotate(t_stack *stack)
{
	t_node *old_top;

	if (!stack || stack->size < 2)
		return;

	old_top = stack->top;

	// Le nouveau top devient le deuxième élément
	stack->top = old_top->next;
	stack->top->prev = NULL;

	// L'ancien top va à la fin
	old_top->next = NULL;
	old_top->prev = stack->bottom;
	stack->bottom->next = old_top;
	stack->bottom = old_top;
}

static void reverse_rotate(t_stack *stack)
{
	t_node *old_bottom;

	if (!stack || stack->size < 2)
		return;

	old_bottom = stack->bottom;

	// Le nouveau bottom devient l'avant-dernier élément
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;

	// L'ancien bottom va au début
	old_bottom->prev = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
}

void ra(t_stack *a)
{
	rotate(a);
	printf("ra\n");
}

void rb(t_stack *b)
{
	rotate(b);
	printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

void rra(t_stack *a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void rrb(t_stack *b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
