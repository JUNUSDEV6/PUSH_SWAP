/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:44:53 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/02 14:45:23 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->index;
	}
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int i)
{
	int	chunk_size;
	int	chunks;

	assign_index(a);
	if (a->size <= 100)
		chunks = 5;
	else
		chunks = 11;
	chunk_size = a->size / chunks;
	while (a->size > 3)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= 1 + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

int	find_best_target(t_stack *a, int b_value)
{
	t_node	*current;
	int		target;
	int		best_target;

	current = a->top;
	target = INT_MAX;
	best_target = find_max(a);
	while (current)
	{
		if (current->value > b_value && current->value < target)
		{
			target = current->value;
			best_target = current->value;
		}
		current = current->next;
	}
	return (best_target);
}
