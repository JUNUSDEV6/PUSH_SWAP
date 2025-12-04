/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:01:04 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/02 14:01:58 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <unistd.h>

static void	push(t_stack *from, t_stack *to)
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

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
