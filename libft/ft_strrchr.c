/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:48:34 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 17:23:24 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (ptr);
}
