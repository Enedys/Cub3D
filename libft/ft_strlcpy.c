/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:41:57 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/07 19:04:20 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *src, size_t n)
{
	const char	*s;

	s = src;
	if (n != 0)
	{
		while (--n && *s)
			*d++ = *s++;
		*d = '\0';
	}
	while (*s)
		s++;
	return (s - src);
}
