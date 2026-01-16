/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:03:16 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:26:49 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (false);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	has_duplicates_in_args(char **argv)
{
	int		i;
	int		j;
	long	val1;
	long	val2;

	i = 0;
	while (argv[i])
	{
		val1 = ft_atol(argv[i], 1);
		j = i + 1;
		while (argv[j])
		{
			val2 = ft_atol(argv[j], 1);
			if (val1 == val2)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	validate_all_args(char **argv)
{
	int		i;
	long	nb;

	if (!argv)
		return (true);
	i = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (false);
		nb = ft_atol(argv[i], 1);
		if (nb > INT_MAX || nb < INT_MIN)
			return (false);
		i++;
	}
	return (!has_duplicates_in_args(argv));
}

static void	add_node(t_stack *stack, int nb)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	set_stack(new_node, nb);
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
}

void	init_stack(t_stack *stack, char **argv)
{
	int		i;
	long	nb;

	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	if (!argv)
		return ;
	if (!validate_all_args(argv))
	{
		free_stack(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i], 1);
		add_node(stack, (int)nb);
		i++;
	}
}
