/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:00:15 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/12/14 14:04:31 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	int				len;
    t_stack_node	*first_node = *stack;
    t_stack_node	*last_node = find_last_node(*stack);

	len = ft_stacklen(*stack);
	if (!*stack || !(*stack)->next || len = 1)
        return ;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    last_node->next = first_node;
    first_node->prev = last_node;
    *stack = last_node;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
}
