/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:29:44 by yohanafi          #+#    #+#             */
/*   Updated: 2023/12/14 14:11:06 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	function to find the last node and return the value
*/
t_stack_node *find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
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
/*
int	main()
{
	t_stack_node	*a;

	a = NULL;
	char	*v[5] = {v[0]="25", v[1] = "42", v[2] = "1337", v[3]= "-21", v[4]= NULL};
	init_stack(&a, v+1, false);
	while (a)
	{
		printf("\n%d, \t node adress %p\n", a->value, a);
		a = a->next;
	}
}
*/