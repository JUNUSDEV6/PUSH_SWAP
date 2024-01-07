/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:08:35 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/07 11:15:00 by youneshanaf      ###   ########.fr       */
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
t_stack_node	*get_cheapest(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
void			init_stack(t_stack_node **a, char **argv, bool flag);
void			prep_for_push(t_stack_node *a,
	t_stack_node *node_to_top,	char name_stack);
int				ft_stacklen(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/*-------OPERATION_&_COMMAND-------*/
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/*-------ALGO_TURC_&_UTILS-------*/
void			current_index(t_stack_node *a);
void			set_cheapest(t_stack_node *stack);
void			algo_a_to_b(t_stack_node *a, t_stack_node *b);
void			algo_b_to_a(t_stack_node *a, t_stack_node *b);
void			min_on_top(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

#endif