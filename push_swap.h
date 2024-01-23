/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:08:26 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/23 11:26:36 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h> 
# include <unistd.h>

typedef struct	s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

/*--------LIBFT--------*/
char			**ft_split(char *str, char sep);
int				ft_printf(const char *format, ...);

/*--------ERROR--------*/
int				error_syntax(char *str_nbr);
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag);
int				error_repition(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);

/*--------STACK & UTILS--------*/
int				stacklen(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			init_stack(t_stack_node **a, char **argv, bool flag);
void			prep_for_push(t_stack_node **stack, t_stack_node *top, char name);
void			min_on_top(t_stack_node **a);
t_stack_node	*get_cheapest(t_stack_node * stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/*--------OPERATIONS & COMMANDS--------*/

void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **b, t_stack_node **a, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

/*--------ALGO & UTILS--------*/

void			current_index(t_stack_node *a);
void			set_cheapest(t_stack_node *stack);
void			init_a(t_stack_node *a, t_stack_node *b);
void			init_b(t_stack_node *a, t_stack_node *b);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

#endif