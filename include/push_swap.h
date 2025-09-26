#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

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

#endif