/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:06:30 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/14 11:41:48 by youneshanaf      ###   ########.fr       */
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
	bool				above_m;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

/*****---split---*****/
char			**ft_split(char *str, char sep);
static int		cnt_words(char *str, char sep);
static char		*get_next_words(char *str, char sep);
/*****---error---*****/
void			error_free(t_stack_node **a, char **argv, bool flag);
int				error_repition(t_stack_node *a, int nbr);
/*****---node---*****/
t_stack_node	*find_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int nbr);
int				ft_atol(const char *str);
int				ft_stacklen(t_stack_node *stack);
#endif