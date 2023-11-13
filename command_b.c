/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:30 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/13 15:59:17 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack_node **b)
{
	swap(b);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

void	rb(t_stack_node **b)
{
	rotate(b);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
}
