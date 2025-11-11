/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/04 19:09:26 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

static void	push(t_stack *from, t_stack *to)
{
	t_node	*node_to_move;

	if (!from || !to || from->size == 0)
		return ;

	node_to_move = from->top;

	// Retirer de la stack source
	from->top = node_to_move->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;

	// Ajouter à la stack destination
	node_to_move->next = to->top;
	node_to_move->prev = NULL;
	
	if (to->top)
		to->top->prev = node_to_move;
	else
		to->bottom = node_to_move;
	
	to->top = node_to_move;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	printf("pb\n");
}
