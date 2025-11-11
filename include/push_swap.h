#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct  s_node
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

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// Function prototypes
void	init_stack(t_stack *stack, char **argv);
void	print_stack(t_stack *stack, char *name);
char	**ft_split(char const *s, char c);

// Operations
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

// Utils
bool	is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);

// Algorithms
void	push_swap(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

// Silent operations (for checker)
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