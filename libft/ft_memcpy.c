/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:27:29 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 01:56:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*start;

	start = dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*((t_uchar *)dest++) = *((t_uchar *)src++);
	return (start);
}
