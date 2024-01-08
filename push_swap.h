/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:08:35 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/08 22:04:33 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h> 
# include <unistd.h>

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

/*-------LIBFT-------*/
char			**ft_split(char *str, char sep);
int				ft_printf(const char *format, ...);

/*-------ERROR-------*/
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag);
int				error_repition(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);

/*-------STACK_&_UTILS-------*/
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_big(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
void			init_stack(t_stack_node **a, char **argv, bool flag);
void			prep_for_push(t_stack_node **stack, t_stack_node *top, char name);
int				ft_stacklen(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

/*-------OPERATION_&_COMMAND-------*/
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **b, t_stack_node **a, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

/*-------ALGO_TURC_&_UTILS-------*/
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			algo_a_to_b(t_stack_node *a, t_stack_node *b);
void			algo_b_to_a(t_stack_node *a, t_stack_node *b);
void			min_on_top(t_stack_node **a);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

#endif