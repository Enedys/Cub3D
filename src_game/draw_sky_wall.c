/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 00:37:42 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:03 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	determine_cell(t_linker *link)
{
	int		res;
	char	sign;

	sign = link->collision->side;
	if (sign == 'u')
		link->texture->tmp = link->texture->no;
	else if (sign == 'd')
		link->texture->tmp = link->texture->so;
	else if (sign == 'l')
		link->texture->tmp = link->texture->we;
	else
		link->texture->tmp = link->texture->ea;
	if (sign == 'u' || sign == 'd')
		res = (((int)link->collision->x1) % link->texture->tmp->width);
	else
		res = (((int)link->collision->y1) % link->texture->tmp->width);
	return (res);
}

static int	change_color(int color, int y, t_linker *link)
{
	int		red;
	int		green;
	int		blue;
	float	a;

	red = (color & r) >> 16;
	green = (color & g) >> 8;
	blue = (color & b);
	green = (green > 128 * y / 256 ? green - 128 * y / 256 : 0);
	red = (red > 32 * y / 256 ? red - 32 * y / 256 : 0);
	blue = (blue + 20 * y / 256 < 255 ? blue + 20 * y / 256 : 255);
	if (link->collision->height < link->ident->res[1] / 4)
	{
		a = 1 + (link->collision->height - link->ident->res[1] / 4.) /
				link->ident->res[1];
		red *= a;
		blue *= a;
		green *= a;
	}
	return (red << 16 | green << 8 | blue);
}

void		draw_wall(t_linker *link, int x0, int y0)
{
	int		i;
	int		x_cord;
	int		color;
	int		y_pixel;

	x_cord = determine_cell(link);
	i = (y0 < 0) ? -y0 : 0;
	i + y0 > 0 ? set_pixel(link, x0, i + y0++, 0) : 0;
	while (i < link->collision->height)
	{
		if (i + y0 > link->ident->res[1])
			return ;
		y_pixel = i * link->texture->tmp->height * 1. / link->collision->height;
		color = *((int *)get_pixel_ptr(link->texture->tmp, x_cord, y_pixel));
		if (link->wall_regime % 2 == 1)
			color = change_color(color, y_pixel, link);
		set_pixel(link, x0, y0 + i, color);
		link->wall_refl = 1;
		draw_floor_pixel(link, (link->ident->res[1] + link->collision->height) \
							- i - y0, x0, color);
		i++;
	}
}

void		draw_sky(t_linker *link, int x0, int y0)
{
	int		color;
	int		start_position;
	float	height_deform;
	int		z;

	z = 0;
	height_deform = 2 * link->texture->sky->height / link->ident->res[1];
	start_position = link->ident->pos->dir * link->texture->sky->width / 360;
	if (y0 <= 0)
		return ;
	while (z < y0)
	{
		if (link->sky_regime % 2 == 1)
			color = *((int *)get_pixel_ptr(link->texture->sky,
			start_position + x0 * height_deform, z * height_deform));
		else
			color = link->ident->c_color[0] << 16 | link->ident->c_color[1] << 8
			| link->ident->c_color[2];
		set_pixel(link, x0, z, color);
		link->wall_refl = 0;
		if (z < (link->ident->res[1] / 2 - 1.5 * link->collision->height))
			draw_floor_pixel(link, link->ident->res[1] - z, x0, color);
		z++;
	}
}
