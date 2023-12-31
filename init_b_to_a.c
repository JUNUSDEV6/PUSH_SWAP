/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:19:36 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/08 21:59:51 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_biggest(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match;

	while (b)
	{
		current_a = a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				target_node = current_a;
				best_match = current_a->value;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	algo_b_to_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_biggest(a, b);
}
