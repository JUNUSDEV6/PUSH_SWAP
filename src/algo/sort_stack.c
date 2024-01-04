/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:30:38 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/04 18:46:56 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if(cheapest_node->median && cheapest_node->target_node->median)
		rotate_both(a, b, false);
	else if (!(cheapest_node->median) && !(cheapest_node->target_node->median))
		rev_rotate_both(a, b, false);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node, 'b');
	pb(a, b, false);

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