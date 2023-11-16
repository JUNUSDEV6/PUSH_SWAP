/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:38 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/16 13:17:38 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *a)
{
	int	median;
	int	i;

	i = 0;
	median = ft_stacklen(a) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

void	target_smaller(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		current_b = b;
		best_match_index = LONG_MIN;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				target_node = current_b;
				best_match_index = current_b->nbr;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_big(a);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
void	cost_operation(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost = len_b - (a->target_node->index);
		a = a->next;
	}
}

void	algo_a_to_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_smaller(a, b);
	cost_operation(a, b);
	set_cheapest(a);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stacklen(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		algo_a_to_b(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (b)
	{
		algo_b_to_a(a, b);
		move_b_to_a(b);
	}
	find_index(a);
	min_on_top(a);
}