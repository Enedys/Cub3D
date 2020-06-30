/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:45:35 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 23:24:04 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *input, const char *find, size_t n)
{
	size_t		iter;
	char const	*start;

	start = input;
	iter = 0;
	if (!(*find))
		return ((char *)input);
	while (*input)
	{
		while ((input - start + iter < n) && *(find + iter) &&
		*(input + iter) == *(find + iter))
			iter++;
		if (!(*(find + iter)))
			return ((char *)input);
		input++;
		iter = 0;
	}
	return (NULL);
}
