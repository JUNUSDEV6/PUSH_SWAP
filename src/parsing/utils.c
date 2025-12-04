/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:27:23 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 15:41:51 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_stack(t_node *node, int nb)
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

long	ft_atol(char *str)
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
