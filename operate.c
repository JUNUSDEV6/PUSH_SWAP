/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:32 by youneshanaf       #+#    #+#             */
/*   Updated: 2023/11/11 17:30:40 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_stack_node *find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	rotate(t_stack_node **stack)
{
    int             len;
	t_stack_node	*last_node;

	len = ft_stacklen(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

static void	rev_rotate(t_stack_node **stack)
{
	int				len;
    t_stack_node	*first_node = *stack;
    t_stack_node	*last_node = find_last_node(*stack);

	len = ft_stacklen(*stack);
	if (!*stack || !(*stack)->next || len = 1)
        return ;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    last_node->next = first_node;
    first_node->prev = last_node;
    *stack = last_node;
}

static void swap(t_stack_node **stack)
{
    int len;

    len = ft_stacklen(*stack);
    if (!*stack || !stack || len == 1)
        return ;
    (*stack) = (*stack)->next;
    (*stack)->prev->prev = (*stack);
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL; 

}

static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_push;

	if (!*src || !src)
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}

int main(void)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Créez une pile a avec trois nœuds
    a = malloc(sizeof(t_stack_node));
    a->next = malloc(sizeof(t_stack_node));
    a->next->next = malloc(sizeof(t_stack_node));
    a->value = 42;
    a->next->value = 1337;
    a->next->next->value = 19;
    a->prev = NULL;
    a->next->prev = a;
    a->next->next->prev = a->next;
    a->next->next->next = NULL;

    // Affichez la pile avant les opérations
    printf("Pile a avant les opérations:\n");
    t_stack_node *current = a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    // Effectuez des opérations de rotation
    rotate(&a);
    printf("Pile a après la rotation:\n");
    current = a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    rev_rotate(&a);
    printf("Pile a après la rotation inverse:\n");
    current = a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    // Testez la fonction push en ajoutant un élément à la pile b
    push(&a, &b);
    printf("Pile a après le push:\n");
    current = a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    printf("Pile b après le push:\n");
    current = b;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    // N'oubliez pas de libérer la mémoire allouée

    return 0;
}
