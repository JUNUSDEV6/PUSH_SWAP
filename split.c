/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:27:19 by yohanafi          #+#    #+#             */
/*   Updated: 2023/10/16 15:54:23 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
#include <stdbool.h>

static int	cnt_words(char *str, char sep)
{
	int		cnt;
	bool	inside_word;
	
	while(*str)
	{
		inside_word = false;
		while(*str == sep)
			str++;
		while(*str != sep && *str)
		{
			if(!inside_word)
			{
				inside_word = true;
				cnt++;
			}	
			cnt++;	
		}
	}
	return (cnt);
}

static char	*get_next_words(char *str, char sep)
{
	static int	w_sp = 0;
	int			len;
	int			i;
	char		*next_str;

	len = 0;
	i = 0;
	while (str[w_sp] == sep)
		w_sp++;
	while (str[w_sp] != sep)
		len++;
	next_str = malloc((size_t) lensizeof(char *));
	if (!next_str)
		return (NULL);
	while (str[len + w_sp] && *str)
		next_str[i++] = str[w_sp];
	next_str[i] = '\0';
	return (next_str);
	
}

char	**ft_split(char *str, char sep)
{
	int		words_nbr;
	int 	i;
	char	**v_str;

	i = 0;
	words_nbr = cnt_words(str, sep);
	v_str = malloc(sizeof(char *) * (words_nbr + 2));
	if (!v_str)
		return (NULL);
	while(words_nbr-- >= 0)
	{
		if (i == 0)
		{
			v_str[i]= malloc(sizeof(char));
			if (!v_str[i])
				return (NULL);
			v_str[i++][0] = '\0';
			continue;
		}
		v_str[i++] = get_next_words(str, sep);
	}
	v_str[i] = NULL;
	return (v_str);
}
