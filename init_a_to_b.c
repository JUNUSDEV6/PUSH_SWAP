/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:38 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/15 16:22:15 by youneshanaf      ###   ########.fr       */
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