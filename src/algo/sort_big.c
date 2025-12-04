/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/04 19:09:27 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	assign_index(t_stack *stack)
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
		current = current->next;
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunks;
	int	i;

	assign_index(a);
	
	if (a->size <= 100)
		chunks = 7;
	else
		chunks = 11;
	
	chunk_size = a->size / chunks;
	i = 0;

	while (a->size > 3)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

static int	find_best_target(t_stack *a, int b_value)
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

static int	calculate_moves(t_stack *a, t_stack *b, int target)
{
	int	moves_a;
	int	moves_b;
	int	pos_a;
	int	pos_b;

	pos_a = find_position(a, target);
	pos_b = find_position(b, b->top->value);

	// Calculer les mouvements pour a
	if (pos_a <= a->size / 2)
		moves_a = pos_a;
	else
		moves_a = a->size - pos_a;

	// Calculer les mouvements pour b
	if (pos_b <= b->size / 2)
		moves_b = pos_b;
	else
		moves_b = b->size - pos_b;

	return (moves_a + moves_b);
}

static void	execute_moves(t_stack *a, t_stack *b, int target, int b_value)
{
	int	pos_a;
	int	pos_b;

	pos_a = find_position(a, target);
	pos_b = find_position(b, b_value);

	// Positionner b_value en haut de b
	if (pos_b <= b->size / 2)
	{
		while (b->top->value != b_value)
			rb(b);
	}
	else
	{
		while (b->top->value != b_value)
			rrb(b);
	}

	// Positionner target en haut de a
	if (pos_a <= a->size / 2)
	{
		while (a->top->value != target)
			ra(a);
	}
	else
	{
		while (a->top->value != target)
			rra(a);
	}

	pa(a, b);
}

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

		// Trouver le meilleur élément à pousser
		while (current)
		{
			best_target = find_best_target(a, current->value);
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
	{
		while (a->top->value != min_val)
			ra(a);
	}
	else
	{
		while (a->top->value != min_val)
			rra(a);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;

	push_chunks_to_b(a, b);
	sort_small(a, b);
	push_back_to_a(a, b);
	final_rotation(a);
}
