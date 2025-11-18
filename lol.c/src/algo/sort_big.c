/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:27:42 by yohanafi          #+#    #+#             */
/*   Updated: 2025/11/13 15:14:40 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		best_value;
	int		best_target;
	int		min_moves;
	int		current_moves;

	while (b->size > 0)
	{
		current = b->top;
		min_moves = INT_MAX;
		best_value = current->value;
		while (current)
		{
			best_target = find_best_target(a, current);
			current_moves = calculate_moves(a, b, best_target);
			if (current_moves < min_moves)
			{
				min_moves = current_moves;
				best_value = current->value;
			}
			current = current->next;
		}
		best_target = find_best_target(a, best_value);
		execute_moves(a, b, best_target, best_value);
	}
}

static void	final_rotation(t_stack *a)
{
	int	min_val;
	int	min_pos;

	min_val = find_min(a);
	min_pos = find_position(a, min_val);
	if (min_pos <= a->size / 2)
		while (a->top->value != min_val)
			ra(a);
	else
		while (a->top->value != min_val)
			rra(a);
}

void	sort_big(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	push_to_b(a, b);
	sort_small(a, b);
	push_back_to_a(a, b);
	final_rotation(a);
}
