/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:12:47 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/13 15:59:11 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	swap(a);
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
}

void	ra(t_stack_node **a)
{
	rotate(a);
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
}
