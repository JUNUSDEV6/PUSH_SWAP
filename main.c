/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:44:17 by yohanafi          #+#    #+#             */
/*   Updated: 2023/10/18 11:46:35 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	main(int argc, char **argv)
{
	int i = 0;
	argv = ft_split("12 56 89 96", 32);
	while (argv[i])
	{
		printf("pointer :%p , %s", argv[i], argv[i]);
		i++;
		fflush(stdout);
	}

	i = 0;
	while (argv[i])
	{
		printf("pointer being freed %p\n\n", argv[i]);
		fflush(stdout);
		free(argv[i++]);
	}
	free(argv);
}