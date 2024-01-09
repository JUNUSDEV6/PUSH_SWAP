/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:45 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/09 14:52:52 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*node_big;

	node_big = find_big(*a);
	if (*a == node_big)
		ra(a, false);
	else if ((*a)->next == node_big)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
