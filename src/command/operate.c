/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:32 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/12/14 14:04:19 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node *find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	rotate(t_stack_node **stack)
{
    int             len;
	t_stack_node	*last_node;

	len = ft_stacklen(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

void	rev_rotate(t_stack_node **stack)
{
	int				len;
    t_stack_node	*first_node = *stack;
    t_stack_node	*last_node = find_last_node(*stack);

	len = ft_stacklen(*stack);
	if (!*stack || !(*stack)->next || len = 1)
        return ;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    last_node->next = first_node;
    first_node->prev = last_node;
    *stack = last_node;
}

void swap(t_stack_node **stack)
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

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_push;

	if (!*src || !src)
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}
