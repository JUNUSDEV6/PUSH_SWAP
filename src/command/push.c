/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:51 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/12/14 14:02:58 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_push;

	if (!*src || !src)
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
}
