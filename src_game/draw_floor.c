/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:11:42 by Kwillum           #+#    #+#             */
/*   Updated: 2020/06/29 18:59:00 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	mix_floor_color(int f_color, int u_color, int wall)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	float	a;

	if (wall == 0)
		a = 0.5;
	else
		a = 0.6;
	red = ((1 - a) * ((u_color & r) >> 16) + a * ((f_color & r) >> 16));
	green = ((1 - a) * ((u_color & g) >> 8) + a * ((f_color & g) >> 8));
	blue = ((1 - a) * (u_color & b) + a * (f_color & b));
	color = (red + green + blue) / 3;
	if (wall == 0)
		return (120 * color / 255 << 16 | 80 * color / 255 << 8\
										| 250 * color / 255);
	else
		return (120 * color / 255 << 16 | 70 * color / 255 << 8\
										| 210 * color / 255);
}

void		draw_floor_pixel(t_linker *link, int i, int j, int up_color)
{
	float	x_size;
	float	x_pos;
	float	y_pos;
	int		color;

	if (i > link->ident->res[1])
		return ;
	x_size = MAP_SCALE * link->ident->res[1] / (i - link->ident->res[1] / 2.);
	x_pos = link->ident->pos->x_pos + link->collision->x_dir_plane * x_size /
			2 + j * link->g->bcos[link->collision->a_index] * x_size /
			link->ident->res[0];
	y_pos = link->ident->pos->y_pos - link->collision->y_dir_plane * x_size / 2
	+ j * link->g->bsin[link->collision->a_index] * x_size /
															link->ident->res[0];
	if (link->floor_regime % 2 == 1)
		color = *((int *)get_pixel_ptr(link->texture->floor, abs((int)x_pos %
							link->texture->floor->width),
							abs((int)y_pos % link->texture->floor->height)));
	else
		color = link->ident->f_color[0] << 16 | link->ident->f_color[1] << 8
											| link->ident->f_color[2];
	if (link->floor_reflection % 2 == 1)
		color = mix_floor_color(color, up_color, link->wall_refl);
	set_pixel(link, j, i, color);
}
