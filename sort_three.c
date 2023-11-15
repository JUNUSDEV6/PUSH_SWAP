/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:45 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/14 15:00:37 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*node_big;

	node_big = find_big(*a);
	if (*a == node_big)
		ra(a, false);
	else ((*a)->next == node_big)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}