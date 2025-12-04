/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 15:47:58 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	min_val;

	min_val = find_min(a);
	min_pos = find_position(a, min_val);
	if (min_pos <= a->size / 2)
		while (a->top->value != min_val)
			ra(a);
	else
		while (a->top->value != min_val)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	min_val;
	int	i;

	i = 0;
	while (i < 2)
	{
		min_val = find_min(a);
		min_pos = find_position(a, min_val);
		if (min_pos <= a->size / 2)
			while (a->top->value != min_val)
				ra(a);
		else
			while (a->top->value != min_val)
				rra(a);
		pb(a, b);
		i++;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}
