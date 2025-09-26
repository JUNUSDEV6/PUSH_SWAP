/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 19:03:16 by yohanafi          #+#    #+#             */
/*   Updated: 2025/09/26 19:46:51 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>

static long	ft_atol(char *str)
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
	int	i;
	int	j;
	long	val1;
	long	val2;
	
	i = 0;
	while (argv[i])
	{
		val1 = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			val2 = ft_atol(argv[j]);
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
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (false);
		
		i++;
	}
	return (!has_duplicates_in_args(argv));
}

static void	set_stack(t_node *node, int nb)
{
	if (!node)
		return ;
	node->value = nb;
	node->index = 0;
	node->cost = 0;
	node->target = 0;
	node->above_median = false;
	node->cheapest = false;
	node->next = NULL;
	node->prev = NULL;
}

static void	add_node(t_stack *stack, int nb)
{
	t_node  *new_node;
	
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

void    init_stack(t_stack  *stack, char **argv)
{
	int     i;
	long    nb;

	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	if (!argv)
		return ;
	if (!validate_all_args(argv))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		add_node(stack, (int)nb);
		i++;
	}
}

// Fonction de debug pour afficher la stack
void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;
	
	if (!stack || !name)
		return ;
	
	printf("=== Stack %s (size: %d) ===\n", name, stack->size);
	if (stack->size == 0)
	{
		printf("Stack vide\n");
		return ;
	}
	
	current = stack->top;
	printf("Top -> ");
	while (current)
	{
		printf("%d", current->value);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf(" <- Bottom\n");
	printf("\n");
}
