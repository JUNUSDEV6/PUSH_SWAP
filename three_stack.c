/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:28:17 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/23 11:00:16 by youneshanaf      ###   ########.fr       */
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
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

