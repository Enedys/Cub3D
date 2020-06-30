/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:01:44 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:09 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	calc_left_wepon_border(t_linker *link, int y0)
{
	int k;
	int	color;

	k = link->texture->weapon->width - 1;
	while (k > 0)
	{
		color = *((int *)get_pixel_ptr(link->texture->weapon, k, y0));
		if (color != 0)
			return (k);
		k--;
	}
	return (0);
}

static int	calc_right_wepon_border(t_linker *link, int y0)
{
	int k;
	int	color;

	k = 0;
	while (k < link->texture->weapon->width / 2)
	{
		color = *((int *)get_pixel_ptr(link->texture->weapon, k, y0));
		if (color != 0)
			return (k);
		k++;
	}
	return (0);
}

void		draw_weapon(t_linker *link)
{
	int		left;
	float	y_deform;
	int		i;
	int		j;
	int		color;

	y_deform = 0.35 * link->ident->res[1] / link->texture->weapon->height;
	i = 0;
	while (i < 0.35 * link->ident->res[1])
	{
		j = 0;
		left = calc_left_wepon_border(link, (int)(i / y_deform));
		if (left == 0 && ++i)
			continue;
		j = y_deform * calc_right_wepon_border(link, (int)(i / y_deform));
		while (j < left * y_deform)
		{
			color = *((int *)get_pixel_ptr(link->texture->weapon,
					(int)(j / y_deform), (int)(i / y_deform)));
			set_pixel(link, 0.65 * link->ident->res[0] - 0.3 * y_deform *
	link->texture->weapon->width + j, 0.65 * link->ident->res[1] + i, color);
			j++;
		}
		i++;
	}
}
