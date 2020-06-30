/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:12:44 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/06 22:28:50 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t memb, size_t size)
{
	void	*p;

	p = (void *)malloc(memb * size);
	if (!(p))
		return (NULL);
	ft_bzero(p, size * memb);
	return (p);
}
