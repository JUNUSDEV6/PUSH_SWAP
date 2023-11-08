/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:32 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/08 16:54:55 by youneshanaf      ###   ########.fr       */
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

