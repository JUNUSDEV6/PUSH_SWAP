/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:38 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/07 11:04:35 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	target_smaller(t_stack_node *a, t_stack_node *b)
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
			a->target_node = find_big(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_operation(t_stack_node *a, t_stack_node *b)
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

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	algo_a_to_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_smaller(a, b);
	cost_operation(a, b);
	set_cheapest(a);
}
