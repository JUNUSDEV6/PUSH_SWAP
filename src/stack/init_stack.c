/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:44 by yohanafi          #+#    #+#             */
/*   Updated: 2024/01/04 19:42:55 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(const char *str)
{
	long	rlt;
	char	sign;

	rlt = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		rlt = rlt * 10 + *str - 48;
		str++;
	}
	return (rlt * sign);
}

/*
	create a node with the value 
	& pointe the node *a in the main to this new *node
	& search for the last node and append
*/
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
			
}
/*
	convert to a long 
	& check the error
	& initalize the node
*/
void	init_stack(t_stack_node **a, char **argv, bool flag)
{
	long	nbr;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag);
		if (error_repition(*a, (int)nbr))
			error_free(a, argv, flag);
		append_node(a, (int)nbr);
		argv++;
	}
}

t_stack_node	get_cheapest(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while(stack)
	{
		if(stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node *a, t_stack_node *node_to_top, char name_stack)
{
	while (*stack != node_to_top)
	{
		if(name_stack == 'a')
		{
			if(node_to_top->median)
				ra(a);
			else
				rra(a);
		}
		else if (name_stack == 'b')
		{
			if(node_to_top->median)
				rb(b);
			else
				rrb(b);
		}
	}
}