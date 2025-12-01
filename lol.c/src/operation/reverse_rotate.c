#include "../../include/push_swap.h"
#include <stdio.h>

static void reverse_rotate(t_stack *stack)
{
	t_node *old_bottom;

	if (!stack || stack->size < 2)
		return;
	old_bottom = stack->bottom;
	stack->bottom = old_bottom->prev;
	stack->bottom->next = NULL;
	old_bottom->prev = NULL;
	old_bottom->next = stack->top;
	stack->top->prev = old_bottom;
	stack->top = old_bottom;
}

void rra(t_stack *a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void rrb(t_stack *b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
