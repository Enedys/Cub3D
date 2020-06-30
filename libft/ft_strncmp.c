/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:45:06 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 20:14:40 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *((t_uchar *)s1) == *((t_uchar *)s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*((t_uchar *)s1) - *((t_uchar *)s2));
}
