/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:25:23 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:24:55 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define _POSIX_C_SOURCE 200809L
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

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
bool	is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
char	**ft_split(char const *s, char c, int i, int j);
void	set_stack(t_node *node, int nb);
long	ft_atol(char *str, char sign);

// MAIN
void	init_stack(t_stack *stack, char **argv);
void	push_swap(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	assign_index(t_stack *stack);
void	push_chunks_to_b(t_stack *a, t_stack *b, int i);
int		find_best_target(t_stack *a, int b_value);

// OPERATIONS
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// OPERATIONS SILENT (BONUS)
void	sa_silent(t_stack *a);
void	sb_silent(t_stack *b);
void	ss_silent(t_stack *a, t_stack *b);
void	pa_silent(t_stack *a, t_stack *b);
void	pb_silent(t_stack *a, t_stack *b);
void	ra_silent(t_stack *a);
void	rb_silent(t_stack *b);
void	rr_silent(t_stack *a, t_stack *b);
void	rra_silent(t_stack *a);
void	rrb_silent(t_stack *b);
void	rrr_silent(t_stack *a, t_stack *b);

#endif
