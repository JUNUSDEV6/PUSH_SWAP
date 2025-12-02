/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:25:23 by yohanafi          #+#    #+#             */
/*   Updated: 2025/11/12 18:08:37 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				target;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// UTILS
long	ft_atol(char *str);
void	set_stack(t_node *node, int nb);

// MAIN
void	init_stack(t_stack *stack, char **argv);
void	push_swap(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);

#endif
