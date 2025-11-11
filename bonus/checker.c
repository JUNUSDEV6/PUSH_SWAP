/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:00:00 by yohanafi          #+#    #+#             */
/*   Updated: 2025/10/04 19:09:19 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

static void	execute_operation(char *op, t_stack *a, t_stack *b)
{
	if (strcmp(op, "sa\n") == 0)
		sa_silent(a);
	else if (strcmp(op, "sb\n") == 0)
		sb_silent(b);
	else if (strcmp(op, "ss\n") == 0)
		ss_silent(a, b);
	else if (strcmp(op, "pa\n") == 0)
		pa_silent(a, b);
	else if (strcmp(op, "pb\n") == 0)
		pb_silent(a, b);
	else if (strcmp(op, "ra\n") == 0)
		ra_silent(a);
	else if (strcmp(op, "rb\n") == 0)
		rb_silent(b);
	else if (strcmp(op, "rr\n") == 0)
		rr_silent(a, b);
	else if (strcmp(op, "rra\n") == 0)
		rra_silent(a);
	else if (strcmp(op, "rrb\n") == 0)
		rrb_silent(b);
	else if (strcmp(op, "rrr\n") == 0)
		rrr_silent(a, b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;
	size_t	len;

	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');

	init_stack(&a, argv + 1);
	init_stack(&b, NULL);

	line = NULL;
	len = 0;
	while (getline(&line, &len, stdin) != -1)
	{
		execute_operation(line, &a, &b);
	}

	if (is_sorted(&a) && b.size == 0)
		printf("OK\n");
	else
		printf("KO\n");

	free(line);
	return (0);
}
