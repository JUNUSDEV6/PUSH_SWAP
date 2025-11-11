/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/04 19:29:10 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}
