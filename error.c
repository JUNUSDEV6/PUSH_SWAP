/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:08:29 by yohanafi          #+#    #+#             */
/*   Updated: 2023/10/19 13:14:50 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a, char **argv, bool flag_bool)
{
	exit(1);
}

int	error_repition(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a == nbr)
			return (0);
		a = a->next;
	}
	return (0);
}
