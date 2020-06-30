/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:27:49 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:56:50 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;

	if (n == 0 || d == s)
		return (d);
	else if (d > s)
	{
		while (n--)
			((t_uchar *)d)[n] = ((t_uchar *)s)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((t_uchar *)d)[i] = ((t_uchar *)s)[i];
			i++;
		}
	}
	return (d);
}
