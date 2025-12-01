#include "../../include/push_swap.h"
#include <stdio.h>

static void	push(t_stack *from, t_stack *to)
{
	t_node *node_to_move;

	if (!from || !to || from->size == 0)
		return ;
	node_to_move = from->top;
	from->top = node_to_move->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node_to_move->next = to->top;
	node_to_move->prev = NULL;
	if (to->top)
		to->top->prev = node_to_move;
	else
		to->bottom = node_to_move;
	to->top = node_to_move;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	printf("pb\n");
}