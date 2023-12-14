/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:59:29 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/12/14 14:04:38 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
    int             len;
	t_stack_node	*last_node;

	len = ft_stacklen(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

void	ra(t_stack_node **a)
{
	rotate(a);
}

void	rb(t_stack_node **b)
{
	rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
}
