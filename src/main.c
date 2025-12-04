/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:32:27 by yohanafi          #+#    #+#             */
/*   Updated: 2025/12/04 16:09:28 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ', 0, 0);
	init_stack(&a, argv + 1);
	init_stack(&b, NULL);
	push_swap(&a, &b);
	return (0);
}
