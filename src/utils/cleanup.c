/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 by yohanafi                   #+#    #+#             */
/*   Updated: 2026/01/12 by yohanafi                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup_and_exit(t_stack *a, t_stack *b, char **split, bool split_used)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (split_used && split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}
