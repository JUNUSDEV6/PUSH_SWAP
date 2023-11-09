/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:32 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/09 14:35:19 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

static	void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !stack)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

static	void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_push;

	if (!*src || !src)
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		*(src)->prev = NULL;
	node_push->prev = NULL;
	if (!dest)
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
