/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:09 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/12/14 14:05:59 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void swap(t_stack_node **stack)
{
    int len;

    len = ft_stacklen(*stack);
    if (!*stack || !stack || len == 1)
        return ;
    (*stack) = (*stack)->next;
    (*stack)->prev->prev = (*stack);
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL; 

}

void	sa(t_stack_node **a)
{
	swap(a);
}

void	sb(t_stack_node **b)
{
	swap(b);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}
