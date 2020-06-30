/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:34:26 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:21 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	cleaner(char **ptr, int iter)
{
	while (iter--)
		free(*ptr++);
}

static int	isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\f' ||
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	count_words(char const *s)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (isspace(*s) == 1)
			s++;
		if (!*s)
			break ;
		while (*s && isspace(*s) == 0)
			s++;
		words++;
	}
	return (words);
}

static int	add_words(char **ptr, char const *s)
{
	char	*st;
	size_t	iter;
	char	**tmp;

	iter = 0;
	tmp = ptr;
	while (*s)
	{
		while (isspace(*s) == 1)
			s++;
		if (!*s)
			break ;
		st = (char *)s;
		while (*s && isspace(*s) == 0)
			s++;
		iter++;
		if (!(*ptr++ = ft_substr(st, 0, s - st)))
		{
			cleaner(tmp, iter);
			return (0);
		}
	}
	*ptr = NULL;
	return (1);
}

char		**ft_split_spaces(char const *s)
{
	size_t	n;
	char	**words;

	if (!s)
		return (NULL);
	n = count_words(s);
	if (!(words = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	if (!add_words(words, s))
	{
		free(words);
		return (NULL);
	}
	return (words);
}
