/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:27:23 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/22 14:51:12 by yohanafi         ###   ########.fr       */
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

long	ft_atol(char *str, char sign)
{
	long	rlt;
	long	digit;

	rlt = 0;
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
		digit = *str - 48;
		if (sign == 1)
			if (rlt > (INT_MAX - digit) / 10)
				return (LONG_MAX);
		if (sign == -1)
			if (rlt > (-(INT_MIN + digit)) / 10)
				return (LONG_MIN);
		rlt = rlt * 10 + digit;
		str++;
	}
	return (rlt * sign);
}
