/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:44:13 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:57:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	count;

	if (!s || !f)
		return (NULL);
	ptr = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	count = 0;
	while (*s)
	{
		ptr[count] = f(count, *s);
		count++;
		s++;
	}
	return (ptr);
}
