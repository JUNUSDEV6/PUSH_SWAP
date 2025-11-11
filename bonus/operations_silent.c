/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_silent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/04 19:09:21 by yohanafi         ###   ########.fr       */
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

static void	push_silent(t_stack *from, t_stack *to)
{
	t_node	*node_to_move;

	if (!from || !to || from->size == 0)
		return ;

	node_to_move = from->top;

	from->top = node_to_move->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;

	node_to_move->next = to->top;
	node_to_move->prev = NULL;
	
	if (to->top)
		to->top->prev = node_to_move;
	else
		to->bottom = node_to_move;
	
	to->top = node_to_move;
	to->size++;
}

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

// Silent operations
void	sa_silent(t_stack *a) { swap_silent(a); }
void	sb_silent(t_stack *b) { swap_silent(b); }
void	ss_silent(t_stack *a, t_stack *b) { swap_silent(a); swap_silent(b); }

void	pa_silent(t_stack *a, t_stack *b) { push_silent(b, a); }
void	pb_silent(t_stack *a, t_stack *b) { push_silent(a, b); }

void	ra_silent(t_stack *a) { rotate_silent(a); }
void	rb_silent(t_stack *b) { rotate_silent(b); }
void	rr_silent(t_stack *a, t_stack *b) { rotate_silent(a); rotate_silent(b); }

void	rra_silent(t_stack *a) { reverse_rotate_silent(a); }
void	rrb_silent(t_stack *b) { reverse_rotate_silent(b); }
void	rrr_silent(t_stack *a, t_stack *b) { reverse_rotate_silent(a); reverse_rotate_silent(b); }
