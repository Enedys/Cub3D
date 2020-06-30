/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:03:48 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	set_pixel(t_linker *link, int x, int y, unsigned int color)
{
	void			*dest;

	if (x < link->ident->res[0] && x >= 0 && y < link->ident->res[1] && y >= 0)
	{
		dest = &(((t_uchar *)(link->data))[link->sizeline * y +
											link->bpp / 8 * x]);
		ft_memcpy(dest, &color, link->bpp / 8);
	}
}

void	*get_pixel_ptr(t_tex *tmp, int x, int y)
{
	void	*ptr;

	ptr = &(((t_uchar *)tmp->data_ptr)[tmp->sizeline * y + tmp->bpp / 8 * x]);
	return (ptr);
}
