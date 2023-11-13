/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:51:34 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/13 15:58:53 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra(a);
	rrb(b);
}
