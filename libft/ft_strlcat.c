/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:40:55 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:57:35 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char const	*s;
	char		*d;
	size_t		d_shift;

	d = dest;
	s = src;
	while (n-- && *d)
		d++;
	d_shift = d - dest;
	if (++n == 0)
		return (ft_strlen(src) + d_shift);
	while (--n && *src)
		*d++ = *src++;
	*d = '\0';
	while (*src)
		src++;
	return (d_shift + src - s);
}
