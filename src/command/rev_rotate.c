/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:00:15 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/06 15:59:55 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	first_node = *stack;
	last_node = find_last_node(*stack);
	len = ft_stacklen(*stack);
	if (!*stack || !(*stack)->next || len = 1)
		return ;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rra(a);
	rrb(b);
	if (!print)
		ft_printf("rrr\n");
}
