/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:06:30 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/15 16:19:43 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h> 

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/*-------SPLIT-------*/
char			**ft_split(char *str, char sep);

/*-------ERROR-------*/
void			error_free(t_stack_node **a, char **argv, bool flag);
int				error_repition(t_stack_node *a, int nbr);

/*-------STACK_&_UTILS-------*/
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_big(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
void			init_stack(t_stack_node **a, char **argv, bool flag);
int				ft_atol(const char *str);
int				ft_stacklen(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/*-------OPERATION_&_COMMAND-------*/
void	swap(t_stack_node **stack);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	push(t_stack_node **src, t_stack_node **dest);
void	pa(t_stack_node **b, t_stack_node **a);
void	pb(t_stack_node **a, t_stack_node **b);
void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rev_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

/*-------ALGO_TURC_&_UTILS-------*/
void	sort_three(t_stack_node **a):

#endif