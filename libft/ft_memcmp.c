/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:26:19 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 18:47:41 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *((t_uchar *)s1) == *((t_uchar *)s2))
	{
		s1++;
		s2++;
	}
	return (*((t_uchar *)s1) - *((t_uchar *)s2));
}
